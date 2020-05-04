create database Stud_Enrollment;

use Stud_Enrollment;

CREATE TABLE student(
 regno VARCHAR(30),
 name VARCHAR(50),
 major VARCHAR(30),
 bdate DATE,
 PRIMARY KEY (regno));
desc student;

CREATE TABLE course(
 courseno INT,
 cname VARCHAR(20),
 dept VARCHAR(20),
 PRIMARY KEY (courseno));
desc course;

CREATE TABLE enroll(
 regno VARCHAR(15),
 courseno INT,
 sem INT(3),
 marks INT(4),
 PRIMARY KEY (regno,courseno),
 FOREIGN KEY (regno) REFERENCES student (regno),
 FOREIGN KEY (courseno) REFERENCES course (courseno));
desc enroll;

CREATE TABLE text(
 book_isbn INT(5),
 book_title VARCHAR(20),
 publisher VARCHAR(20),
 author VARCHAR(20),
 PRIMARY KEY (book_isbn));
desc text;

CREATE TABLE book_adoption(
 courseno INT,
 sem INT(3),
 book_isbn INT(5),
 PRIMARY KEY (courseno,book_isbn),
 FOREIGN KEY (courseno) REFERENCES course (courseno) on update cascade,
 FOREIGN KEY (book_isbn) REFERENCES text(book_isbn)on update cascade
);
desc book_adoption;

INSERT INTO student (regno,name,major,bdate) VALUES
 ('1BM19CS404','Md','sr','19930924'),
 ('1BM19CS401','Arbaz','sr','19931127'),
 ('1BM19CS400','Abhishek','sr','19930413'),
 ('1BM19CS402','Chirag','jr','19940824');
select * from student;

INSERT INTO course VALUES (111,'OS','CSE'),
 (112,'TFCS','CSE'),
 (113,'ADA','ISE'),
 (114,'DBMS','CSE'),
 (115,'C','ECE');
select * from course;

INSERT INTO text (book_isbn,book_title,publisher,author)VALUES
 (10,'DATABASE SYSTEMS','PEARSON','SCHIELD'),
 (900,'OPERATING SYS','PEARSON','LELAND'),
 (901,'CIRCUITS','HALL INDIA','BOB'),
 (902,'SYSTEM SOFTWARE','PETERSON','JACOB'),
 (903,'SCHEDULING','PEARSON','PATIL'),
 (904,'DATABASE SYSTEMS','PEARSON','JACOB'),
 (905,'DATABASE MANAGER','PEARSON','BOB'),
 (906,'SIGNALS','HALL INDIA','SUMIT');
select * from text;

INSERT INTO enroll (regno,courseno,sem,marks) VALUES
 ('1BM19CS404',114,5,100),
 ('1BM19CS401',113,5,100),
 ('1BM19CS400',111,5,100),
 ('1BM19CS402',112,3,100);
select * from enroll;

INSERT INTO book_adoption (courseno,sem,book_isbn) VALUES
(111,5,900),
(111,5,903),
(111,5,904),
(112,3,901),
(113,3,10),
(114,5,905),
(113,5,902),
(115,3,906);
select * from book_adoption;
commit;
