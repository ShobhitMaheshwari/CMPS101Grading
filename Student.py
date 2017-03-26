import shutil, errno, subprocess, os
from Test import Test
from timeout import TimeoutError
from pathlib import Path
from os import listdir
from os.path import isfile, join

class Student:
	def __init__ (self, name, path):
		self.name = name
		self.score = 0
		self.points = 0
		self.report = ""
		self.path = path
		self.tests = None

	def copy_dir(self, src, dst):
		try:
			shutil.copytree(src, dst)
		except OSError as exc: # python >2.5
			if exc.errno == errno.ENOTDIR:
				shutil.copy(src, dst)
			else: raise

	def prepare(self):
		#copy student files to temp
		src = os.path.join(self.path, self.name)
		dst = os.path.join(os.getcwd(), 'temp')
		self.copy_dir(src, dst)
		self.copy_dir(os.path.join(os.getcwd(), 'Test'), os.path.join(dst, "Test"))
		with open("testlist") as f:
			content = f.readlines()
			# you may also want to remove whitespace characters like `\n` at the end of each line
			self.tests = [Test(x.strip(), os.path.join(dst, "Test")) for x in content]

	def check_all_files(self):
		mypath = os.path.join(os.getcwd(), 'temp')
		onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
		if(set(['List.c','Graph.c','FindPath.c']) < set(onlyfiles)):
			return 0
		if(set(['List.c','Graph.c']) < set(onlyfiles)):
			return 1
		return 2


	def remove(self):
		#delete temp folder
		shutil.rmtree(os.path.join(os.getcwd(), 'temp'))

	def compile_graph(self):
		try :
			testResults = subprocess.check_output("gcc -std=c99 -c Graph.c", cwd=os.path.join(os.getcwd(), 'temp'), shell=True)
			return True
		except subprocess.CalledProcessError as error :
			return False

	def compile_list(self):
		try :
			testResults = subprocess.check_output("gcc -std=c99 -c List.c", cwd=os.path.join(os.getcwd(), 'temp'), shell=True)
			return True
		except subprocess.CalledProcessError as error :
			return False

	def compile_findpath(self):
		try :
			testResults = subprocess.check_output("gcc -std=c99 -c FindPath.c", cwd=os.path.join(os.getcwd(), 'temp'), shell=True)
			testResults = subprocess.check_output("gcc -std=c99 -o FindPath FindPath.o Graph.o List.o", cwd=os.path.join(os.getcwd(), 'temp'), shell=True)
			return True
		except subprocess.CalledProcessError as error :
			return False


	def grade(self):
		self.prepare()
		status = self.check_all_files()
		print(status)
		self.points += 50
		if(status == 0):
			self.score += 15
			self.report += "15/15 points for submitting relevant (Graph.c, List.c, FindPath.c) files\n"
		if(status == 1):
			self.score += 10
			self.report += "10/15 points for submitting relevant (Graph.c, List.c, FindPath.c) files\n"
		if(status == 2):
			self.report += "0/15 No relevant (Graph.c, List.c, FindPath.c) files submitted\n"

		if(self.compile_list()):
			self.score += 8
			self.report += "8/8 points for compiling List.c\n"
		else:
			self.report += "0/8  List.c compilation failed\n"

		if(self.compile_graph()):
			self.score += 17
			self.report += "17/17 points for compiling Graph.c\n"
		else:
			self.report += "0/17 Graph.c not compile\n"

		if(self.compile_findpath()):
			self.score += 10
			self.report += "10/10 points for compiling FindPath.c\n"
		else:
			self.report += "0/10 points for compiling FindPath.c\n"

		for test in self.tests:
			self.points+=test.points

		#run all tests
		for test in self.tests:
			try:
				test.runTest()
			except TimeoutError as error:
				test.report+="timeout\n"

			self.score+=test.score
			#print("name: "+str(test.name))
			#print("score: " +str(test.score))
			#print("report: " + test.report)

		self.generateReport()
		self.remove()

	def generateReport(self):
		self.report += ("Total score: " + str(self.score) + "/" + str(self.points) + "\n")
		self.report += ("\n-------------\n")
		for test in self.tests:
			self.report += ("name: " + str(test.name) + "\n")
			self.report += ("description: " + str(test.description) + "\n")
			self.report += ("url: " + str(test.url) + "\n")
			self.report += ("score: " + str(test.score) +"/" +str(test.points) + "\n")
			self.report += ("report: " +test.report + "\n")
			self.report += ("test output:\n")
			p = os.path.join(os.path.join(os.getcwd(), 'temp'), "Test")
			my_file = Path((p + "/" + "%s.out")%(test.name))
			if my_file.is_file():
				with open((p + "/" + "%s.out")%(test.name), 'r') as content_file:
					s = 0
					while True:
						c= content_file.read(1)
						s+=1
						if not c:
							break
						if s > 1000:
							break
						self.report+=c

			self.report += ("\n-------------\n")

