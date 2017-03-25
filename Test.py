import os, subprocess, shlex
from timeout import timeout
class Test :
	def __init__ (self, testname, path):
		self.path = path
		self.commands = [command.rstrip() for command in open(os.path.join(path, testname))]
		self.url = self.commands[0]
		self.a, self.b = map(lambda x: int(x), self.commands[1].split())
	 	self.points = self.a + self.b
		self.description = self.commands[2]
		self.name = testname
		self.report = ""
		self.score = 0
		del self.commands[0]
		del self.commands[0]
		del self.commands[0]

	@timeout(25)
	def runTest(self):
		FNULL = open(os.devnull, 'w')
		for command in self.commands:
			try :
				testResults = subprocess.check_output(command, shell=True, cwd=self.path)
			except subprocess.CalledProcessError as error :
				self.report +="Test Failure for command "  + command + "\n"
			#Perform diff comparison of expected output and actual output
		try:
			#raise ValueError('A very specific bad thing happened')
			subprocess.check_call(("diff -w -b %s.out %s.expected") % (self.name, self.name), shell=True, cwd = self.path, stdout=FNULL)
			self.score += self.a
		except :
			try:
				#diff <( tr -d ' \n' <Test_Append.out ) <( tr -d ' \n' <Test_Append.expected)
				#print((str(shlex.quote(("diff <( tr -d ' \\n' <%s.out ) <( tr -d ' \\n' <%s.expected)")% (self.name, self.name)))))
				subprocess.check_output((("tr -d '\'' \\n\\t'\'' <%s.out > %s.1.out")%(self.name, self.name)), shell=True, cwd=self.path, executable='/bin/bash')
#				subprocess.check_output((("tr -dc '\''[[:print:]]'\'' <%s2.out > %s1.out")%(self.name, self.name)), shell=True, cwd=self.path, executable='/bin/bash')
				subprocess.check_output((("tr -d '\'' \\n\\t'\'' <%s.expected > %s.1.expected")%(self.name, self.name)), shell=True, cwd=self.path, executable='/bin/bash')
				subprocess.check_call((("diff %s.1.out %s.1.expected")% (self.name, self.name)), shell=True, cwd = self.path, stdout=FNULL)
				#self.report +=("Test failed due to comparison failure on spaces and newlines.") + "\n"
				self.score += self.a
			except:
				if("Test Failure for command" not in self.report):
					self.report +=("Test failed due to comparison failure.") + "\n"
				return

		#valgrind --leak-check=full ./Test_Constructor >> Test_Constructor.out
		with open(os.path.join(self.path, "memoryLeak")) as f:
			content = f.readlines()
			for line in content:
				if 'no leaks are possible' in line:
					self.report += "ok\n"
					self.score += self.b
					return
		self.report +=("Test failed due to memory leak.") + "\n"
