package com.companyname.bank;
import java.io.File;
import java.io.IOException;
import java.lang.reflect.Array;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Properties;
import java.util.Scanner;

import javax.mail.Message;
import javax.mail.MessagingException;
import javax.mail.PasswordAuthentication;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.AddressException;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;

/**
 * Hello world!
 *
 */
public class App
{
    public static void main( String[] args ) throws IOException
    {
        System.out.println( "Hello World!" );        
        final String username = "shmahesh@ucsc.edu";
        final String password = "";

        Properties props = new Properties();
        props.put("mail.smtp.starttls.enable", "true");
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.host", "smtp.gmail.com");
        props.put("mail.smtp.port", "587");

        Session session = Session.getInstance(props,
          new javax.mail.Authenticator() {
            protected PasswordAuthentication getPasswordAuthentication() {
                return new PasswordAuthentication(username, password);
            }
          });

        try {
        	ArrayList<String> a = new ArrayList<String>();
        	Files.lines(FileSystems.getDefault().getPath("/home/shobhit/workspace/CMPS101/StudentRoster")).forEach((name)->{
        		a.add(name);
        	});
        	for(int i = 0; i < 1; i++){
        		Message message = new MimeMessage(session);
              message.setFrom(new InternetAddress("shmahesh@ucsc.edu"));
              message.setRecipients(Message.RecipientType.TO,InternetAddress.parse("shobhitm.iit@gmail.com"));
//              message.setRecipients(Message.RecipientType.TO,InternetAddress.parse(a.get(i)+"@ucsc.edu"));
              message.setSubject("Revised pa4 grades");
              String content = new Scanner(new File("/home/shobhit/workspace/CMPS101/mossabc/moss-taps/data/Current/pa4/"+a.get(i)+"/report.txt")).useDelimiter("\\Z").next();
              message.setText("Hi "+a.get(i)+","
                  + "\n\n This is an automated email. PFA your score\n" + content);
              Transport.send(message);
        	}
//            
            System.out.println("Done");

        } 
        catch (MessagingException e) {
            throw new RuntimeException(e);
        }
    }
}
