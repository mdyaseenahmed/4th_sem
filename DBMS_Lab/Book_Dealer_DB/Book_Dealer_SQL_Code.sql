create database book_dealer;
use book_dealer;

create table author (
 author_id INT,
 author_name VARCHAR(20),
 author_city VARCHAR(20),
 author_country VARCHAR(20),
 PRIMARY KEY(author_id));
desc author;

 create table publisher (
 publisher_id INT,
 publisher_name VARCHAR(20),
 publisher_city VARCHAR(20),
 publisher_country VARCHAR(20),
 PRIMARY KEY(publisher_id));
desc publisher;

 create table category (
 category_id INT,
 description VARCHAR(30),
 PRIMARY KEY(category_id));
desc category; 

CREATE TABLE catalog(
 book_id INT,
 book_title VARCHAR(30),
 author_id INT,
 publisher_id INT,
 category_id INT,
 year INT,
 price INT,
 PRIMARY KEY(book_id),
 FOREIGN KEY(author_id) REFERENCES author(author_id),
 FOREIGN KEY(publisher_id) REFERENCES publisher(publisher_id),
 FOREIGN KEY(category_id) REFERENCES category(category_id) );
desc catalog;

 CREATE TABLE orderdetails(
 order_id INT,
 book_id INT,
 quantity INT,
 PRIMARY KEY(order_id),
 FOREIGN KEY(book_id) REFERENCES catalog(book_id));
desc orderdetails;

INSERT INTO author (author_id,author_name,author_city,author_country) VALUES
 (1001,'JK Rowling','London','England'),
 (1002,'Chetan Bhagat','Mumbai','India'),
 (1003,'John McCarthy','Chicago','USA'),
 (1004,'Dan Brown','California','USA') ;
 select * from author;

 INSERT INTO publisher (publisher_id,publisher_name,publisher_city,publisher_country) VALUES
 (101,'Bloomsbury','London','England'),
 (102,'Scholastic','Washington','USA'),
 (103,'Pearson','London','England'),
 (104,'Rupa','Delhi','India');
 select * from publisher;

INSERT INTO category (category_id,description) VALUES
 (3001,'Fiction'),
 (3002,'Non-Fiction'),
 (3003,'thriller'),
 (3004,'action'),
 (3005,'fiction') ;
select * from category;

INSERT INTO catalog (book_id,book_title,author_id,publisher_id,category_id,year,price) VALUES
 (4001,'HP and Goblet Of Fire',1001,101,3001,2002,600),
 (4002,'HP and Order Of Phoenix',1001,102,3001,2005,650),
 (4003,'Two States',1002,104,3001,2009,65),
 (4004,'3 Mistakes of my life',1002,104,3001,2007,55),
 (4005,'Da Vinci Code',1004,103,3001,2004,450),
 (4006,'Angels and Demons',1004,103,3001,2003,350),
 (4007,'Artificial Intelligence',1003,102,3002,1970,500);
 select * from catalog;

INSERT INTO orderdetails (order_id,book_id,quantity) VALUES
 (5001,4001,5),
 (5002,4002,7),
 (5003,4003,15),
 (5004,4004,11),
 (5005,4005,9),
 (5006,4006,8),
 (5007,4007,2),
 (5008,4004,3) ;
 select * from orderdetails;

select a.author_id,a.author_city,a.author_name,a.author_city
from author a join catalog c on a.author_id=c.author_id where
year>2000 and c.author_id in(select c.author_id from catalog having
count(c.author_id)>2 and price>500 ); 

select a.author_id from author a join catalog c on
a.author_id=c.author_id join orderdetails o on c.book_id=o.book_id
having max(o.quantity);

update catalog set price=(0.1*price)+price where publisher_id=2001;
 select * from catalog;
commit;
