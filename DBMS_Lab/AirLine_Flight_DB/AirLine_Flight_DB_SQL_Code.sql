/* AirLine Flight Database. */
create database airline;
Query OK, 1 row affected (0.077 sec)

use airline;
Database changed

/* FLIGHT Table */
create table flight(
    fl_no int,
    f_from varchar(40),
    f_to varchar(40),
    distance int,
    departs time,
    arrives time,
    price int,
    primary key(fl_no));
Query OK, 0 row affected (0.263 sec)

desc flight;

/* AIRCRAFT Table */    
create table aircraft(
    aid int,
    aname varchar(40),
    cruisinrange int,
    primary key(aid));
Query OK, 0 row affected (0.247 sec)

desc aircraft;

/* EMPLOYEE Table */
create table employee(
    eid int,
    ename varchar(40),
    salary int,
    primary key(eid));
Query OK, 0 row affected (0.316 sec)

desc employee;

/* CERTIFIED Table */    
create table certified(
    eid int,
    aid int,
    foreign key(eid)references employee(eid),
    foreign key(aid)references aircraft(aid));
Query OK, 0 row affected (0.412 sec)

desc certified;

/* Inserts into FLIGHT Table */
INSERT INTO flight (fl_no, f_from, f_to, distance, departs, arrives, price) VALUES ('101', 'Bangalore', 'Gulbarga', '580', '02:15:00', '03:00:00', '2580');
INSERT INTO flight (fl_no, f_from, f_to, distance, departs, arrives, price) VALUES ('102', 'Delhi', 'Bangalore', '1250', '11:10:00', '12:50:00', '4532');
INSERT INTO flight (fl_no, f_from, f_to, distance, departs, arrives, price) VALUES ('103', 'Mumbai', 'Lucknow', '654', '05:55:00', '06:50:00', '3278');
INSERT INTO flight (fl_no, f_from, f_to, distance, departs, arrives, price) VALUES ('104', 'Delhi', 'Ahmedabad', '450', '01:00:00', '01:50:00', '4555');
INSERT INTO flight (fl_no, f_from, f_to, distance, departs, arrives, price) VALUES ('105', 'Mumbai', 'Bangalore', '680', '02:15:00', '03:30:00', '3580');
INSERT INTO flight (fl_no, f_from, f_to, distance, departs, arrives, price) VALUES ('106', 'Hyderabad', 'frankfurt', '3500', '07:10:00', '09:50:00', '5805');

SELECT * FROM flight;

/* Inserts into AIRCRAFT Table */
INSERT INTO aircraft (aid, aname, cruisinrange) VALUES ('201', 'HAL Tejas', '3205');
INSERT INTO aircraft (aid, aname, cruisinrange) VALUES ('202', 'Boeing', '1580');
INSERT INTO aircraft (aid, aname, cruisinrange) VALUES ('203', 'Airbus', '2356');
INSERT INTO aircraft (aid, aname, cruisinrange) VALUES ('204', 'Cirrus', '3562');
INSERT INTO aircraft (aid, aname, cruisinrange) VALUES ('205', 'Learjet', '4578');

SELECT * FROM aircraft;

/* Inserts into EMPLOYEE Table */
INSERT INTO employee (eid, ename, salary) VALUES ('301', 'Akash', '35875');
INSERT INTO employee (eid, ename, salary) VALUES ('302', 'Yuvraj', '45000');
INSERT INTO employee (eid, ename, salary) VALUES ('303', 'Sunil', '54870');
INSERT INTO employee (eid, ename, salary) VALUES ('304', 'Asim', '81000');
INSERT INTO employee (eid, ename, salary) VALUES ('305', 'Yaseen', '38798');

SELECT * FROM employee;

/* Inserts into CERTIFIED Table */
INSERT INTO `certified` (`eid`, `aid`) VALUES ('301', '201');
INSERT INTO `certified` (`eid`, `aid`) VALUES ('301', '204');
INSERT INTO `certified` (`eid`, `aid`) VALUES ('302', '205');
INSERT INTO `certified` (`eid`, `aid`) VALUES ('303', '203');
INSERT INTO `certified` (`eid`, `aid`) VALUES ('304', '204');
INSERT INTO `certified` (`eid`, `aid`) VALUES ('304', '205');
INSERT INTO `certified` (`eid`, `aid`) VALUES ('305', '202');

SELECT * FROM certified;

/******************** QUERIES ********************/

/* 01. Find the names of Aircraft such that all pilots certified to operate them have salaries more than Rs. 80000 */
select aname from aircraft
where aid in(select c.aid 
from certified c,employee e
where c.eid = e.eid and 
not exists(select * 
from employee e1 where 
e1.eid = e.eid and e1.salary<80000));

/* 02.	For each pilot who is certified for more than three aircrafts, find the eid and the maximum cruising range of the aircraft for which she or he is certified. */
select c.eid,max(a.cruisinrange)
from certified c, aircraft a
where c.aid = a.aid 
group by c.eid having count(*)>=3; 

/* 03.	Find the names of pilots whose salary is less than the price of the cheapest route from Bengaluru to Frankfurt. */
select E.ename from employee E
where salary < (select min(F.price) 
from flight F where F.f_from = 'Bangalore' and F.f_to = 'frankfurt');

/* 04.	For all aircraft with cruising range over 1000 Kms, find the name of the aircraft and the average salary of all pilots certified for this aircraft. */
select A.aname,avg(E.salary)
from aircraft A,employee E,certified C
where A.cruisinrange>=1000 and 
A.aid = C.aid and E.eid = C.eid
group by A.aid,A.aname; 

/* 05. Find the names of pilots certified for some Boeing aircraft. */
select E.ename
from employee E,certified C,aircraft A
where A.aname = 'Boeing' and A.aid = C.aid and E.eid = C.eid; 

commit;
Query OK, 0 rows affected (0.000 sec)
