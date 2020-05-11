create database college;
use college;

CREATE TABLE STUDENT ( 
USN VARCHAR (10) PRIMARY KEY, 
SNAME VARCHAR (25), 
ADDRESS VARCHAR (25), 
PHONE INT (10), 
GENDER CHAR (1)); 

CREATE TABLE SEMSEC ( 
SSID VARCHAR (5) PRIMARY KEY, 
SEM INT (2), 
SEC CHAR (1)); 

CREATE TABLE CLASS ( 
USN VARCHAR (10), 
SSID VARCHAR (5), 
PRIMARY KEY (USN, SSID), 
FOREIGN KEY (USN) REFERENCES STUDENT (USN), 
FOREIGN KEY (SSID) REFERENCES SEMSEC (SSID));

CREATE TABLE SUBJECT ( 
SUBCODE VARCHAR (8), 
TITLE VARCHAR (20), 
SEM INT(2), 
CREDITS INT (2), 
PRIMARY KEY (SUBCODE)); 

CREATE TABLE IAMARKS ( 
USN VARCHAR (10), 
SUBCODE VARCHAR (8), 
SSID VARCHAR (5), 
TEST1 INT(2), 
TEST2 INT(2), 
TEST3 INT(2), 
FINALIA INT(2), 
PRIMARY KEY (USN, SUBCODE, SSID), 
FOREIGN KEY (USN) REFERENCES STUDENT (USN), 
FOREIGN KEY (SUBCODE) REFERENCES SUBJECT (SUBCODE), 
FOREIGN KEY (SSID) REFERENCES SEMSEC (SSID));

desc student;
desc semsec;
desc class;
desc subject;
desc iamarks;

INSERT INTO STUDENT VALUES ('1RN13CS020','AKSHAY','BELAGAVI', 1232654578,'M'); 
INSERT INTO STUDENT VALUES ('1RN13CS062','SANDHYA','BENGALURU', 1232654578,'F'); 
INSERT INTO STUDENT VALUES ('1RN13CS091','TEESHA','BENGALURU', 1232654578,'F'); 
INSERT INTO STUDENT VALUES ('1RN13CS066','SUPRIYA','MANGALURU', 1232654578,'F'); 
INSERT INTO STUDENT VALUES ('1RN14CS010','ABHAY','BENGALURU', 1232654578,'M'); 
INSERT INTO STUDENT VALUES ('1RN14CS032','BHASKAR','BENGALURU', 1232654578,'M'); 
INSERT INTO STUDENT VALUES ('1RN14CS025','ASMI','BENGALURU', 1232654578,'F'); 
INSERT INTO STUDENT VALUES ('1RN15CS011','AJAY','TUMKUR', 1232654578,'M');
INSERT INTO STUDENT VALUES ('1RN15CS029','CHITRA','DAVANGERE', 1232654578,'F'); 
INSERT INTO STUDENT VALUES ('1RN15CS045','JEEVA','BELLARY', 1232654578,'M'); 
INSERT INTO STUDENT VALUES ('1RN15CS091','SANTOSH','MANGALURU', 1232654578,'M'); 
INSERT INTO STUDENT VALUES ('1RN16CS045','ISMAIL','KALBURGI', 1232654578,'M'); 
INSERT INTO STUDENT VALUES ('1RN16CS088','SAMEERA','SHIMOGA', 1232654578,'F'); 
INSERT INTO STUDENT VALUES ('1RN16CS122','VINAYAKA','CHIKAMAGALUR', 1232654578,'M');
select * from student;

INSERT INTO SEMSEC VALUES ('CSE8A', 8,'A'); 
INSERT INTO SEMSEC VALUES ('CSE8B', 8,'B'); 
INSERT INTO SEMSEC VALUES ('CSE8C', 8,'C'); 
INSERT INTO SEMSEC VALUES ('CSE7A', 7,'A'); 
INSERT INTO SEMSEC VALUES ('CSE7B', 7,'B'); 
INSERT INTO SEMSEC VALUES ('CSE7C', 7,'C'); 
INSERT INTO SEMSEC VALUES ('CSE6A', 6,'A'); 
INSERT INTO SEMSEC VALUES ('CSE6B', 6,'B'); 
INSERT INTO SEMSEC VALUES ('CSE6C', 6,'C'); 
INSERT INTO SEMSEC VALUES ('CSE5A', 5,'A'); 
INSERT INTO SEMSEC VALUES ('CSE5B', 5,'B'); 
INSERT INTO SEMSEC VALUES ('CSE5C', 5,'C'); 
INSERT INTO SEMSEC VALUES ('CSE4A', 4,'A'); 
INSERT INTO SEMSEC VALUES ('CSE4B', 4,'B'); 
INSERT INTO SEMSEC VALUES ('CSE4C', 4,'C'); 
INSERT INTO SEMSEC VALUES ('CSE3A', 3,'A'); 
INSERT INTO SEMSEC VALUES ('CSE3B', 3,'B'); 
INSERT INTO SEMSEC VALUES ('CSE3C', 3,'C'); 
INSERT INTO SEMSEC VALUES ('CSE2A', 2,'A'); 
INSERT INTO SEMSEC VALUES ('CSE2B', 2,'B'); 
INSERT INTO SEMSEC VALUES ('CSE2C', 2,'C'); 
INSERT INTO SEMSEC VALUES ('CSE1A', 1,'A');
INSERT INTO SEMSEC VALUES ('CSE1B', 1,'B'); 
INSERT INTO SEMSEC VALUES ('CSE1C', 1,'C');
select * from semsec;

INSERT INTO CLASS VALUES ('1RN13CS020','CSE8A'); 
INSERT INTO CLASS VALUES ('1RN13CS062','CSE8A'); 
INSERT INTO CLASS VALUES ('1RN13CS066','CSE8B'); 
INSERT INTO CLASS VALUES ('1RN13CS091','CSE8C'); 
INSERT INTO CLASS VALUES ('1RN14CS010','CSE7A'); 
INSERT INTO CLASS VALUES ('1RN14CS025','CSE7A'); 
INSERT INTO CLASS VALUES ('1RN14CS032','CSE7A'); 
INSERT INTO CLASS VALUES ('1RN15CS011','CSE4A'); 
INSERT INTO CLASS VALUES ('1RN15CS029','CSE4A'); 
select * fom class;

INSERT INTO SUBJECT VALUES ('10CS81','ACA', 8, 4); 
INSERT INTO SUBJECT VALUES ('10CS82','SSM', 8, 4); 
INSERT INTO SUBJECT VALUES ('10CS83','NM', 8, 4); 
INSERT INTO SUBJECT VALUES ('10CS84','CC', 8, 4); 
INSERT INTO SUBJECT VALUES ('10CS85','PW', 8, 4); 
INSERT INTO SUBJECT VALUES ('10CS71','OOAD', 7, 4); 
INSERT INTO SUBJECT VALUES ('10CS72','ECS', 7, 4); 
INSERT INTO SUBJECT VALUES ('10CS73','PTW', 7, 4); 
INSERT INTO SUBJECT VALUES ('10CS74','DWDM', 7, 4);
select * from subject;

INSERT INTO IAMARKS (USN, SUBCODE, SSID, TEST1, TEST2, TEST3) VALUES ('1RN13CS091','10CS81','CSE8C', 15, 16, 18); 
INSERT INTO IAMARKS (USN, SUBCODE, SSID, TEST1, TEST2, TEST3) VALUES ('1RN13CS091','10CS82','CSE8C', 12, 19, 14); 
INSERT INTO IAMARKS (USN, SUBCODE, SSID, TEST1, TEST2, TEST3) VALUES ('1RN13CS091','10CS83','CSE8C', 19, 15, 20); 
INSERT INTO IAMARKS (USN, SUBCODE, SSID, TEST1, TEST2, TEST3) VALUES ('1RN13CS091','10CS84','CSE8C', 20, 16, 19); 
INSERT INTO IAMARKS (USN, SUBCODE, SSID, TEST1, TEST2, TEST3) VALUES ('1RN13CS091','10CS85','CSE8C', 15, 15, 12);
select * from iamarks;

/*  List all the student details studying in fourth semester ‘A’ section */

SELECT S.*, SS.SEM, SS.SEC 
FROM STUDENT S, SEMSEC SS, CLASS C 
WHERE S.USN = C.USN AND SS.SSID = C.SSID AND SS.SEM = 4 AND SS.SEC='A';

/*  Compute the total number of male and female students in each semester and in each section */

SELECT SS.SEM, SS.SEC, S.GENDER, COUNT(S.GENDER) AS COUNT 
FROM STUDENT S, SEMSEC SS, CLASS C 
WHERE S.USN = C.USN AND 
SS.SSID = C.SSID 
GROUP BY SS.SEM, SS.SEC, S.GENDER 
ORDER BY SEM;

/*  Create a view of Test1 marks of student USN ‘1BI15CS101’ in all subjects */

CREATE VIEW STU_TEST1_MARKS_VIEW 
AS 
SELECT TEST1, SUBCODE 
FROM IAMARKS 
WHERE USN = '1RN13CS091';
select * from STU_TEST1_MARKS_VIEW;

/*  Categorize students based on the following criterion: 

If FinalIA = 17 to 20 then CAT = ‘Outstanding’ 
If FinalIA = 12 to 16 then CAT = ‘Average’ 
If FinalIA< 12 then CAT = ‘Weak’ 
Give these details only for 8th semester A, B, and C section students */

SELECT S.USN,S.SNAME,S.ADDRESS,S.PHONE,S.GENDER, 
(CASE 
WHEN IA.FINALIA BETWEEN 17 AND 20 THEN 'OUTSTANDING' 
WHEN IA.FINALIA BETWEEN 12 AND 16 THEN 'AVERAGE' 
ELSE 'WEAK' 
END) AS CAT 
FROM STUDENT S, SEMSEC SS, IAMARKS IA, SUBJECT SUB 
WHERE S.USN = IA.USN AND 
SS.SSID = IA.SSID AND 
SUB.SUBCODE = IA.SUBCODE AND 
SUB.SEM = 8;
commit;
