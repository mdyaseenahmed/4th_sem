/* Order Processing Database. */
create database order_processing;
Query OK, 1 row affected (0.077 sec)

use order_processing;
Database changed

/* CUSTOMER Table */
create table customer(
    cust_id int,
    cnmae varchar(30),
    city varchar(40),
    primary key(cust_id));
Query OK, 0 row affected (0.262 sec)

desc customer;

/* ORDERS Table */
create table orders(
    order_no int,
    odate date,
    cust_id int,
    ord_amt int,
    primary key(order_no),
    foreign key(cust_id)references customer (cust_id));
Query OK, 0 row affected (0.328 sec)

desc orders;

/* ITEM Table */
create table item(
    item_id int,
    price int,
    primary key(item_id));
Query OK, 0 row affected (0.261 sec)

desc item;

/* ORDER_ITEM Table */
create table order_item(
    order_no int,
    item_id int,
    qty int,
    foreign key(order_no)references orders (order_no),
    foreign key(item_id)references item(item_id)on delete set NULL);
Query OK, 0 row affected (0.335 sec)

desc order_item;

/* WAREHOUSE Table */ 
create table warehouse(
    warehouse_id int,
    city varchar(40),
    primary key(warehouse_id));
Query OK, 0 row affected (0.232 sec)

desc warehouse;

/* SHIPMENT Table */
create table shipment(
    order_no int,
    warehouse_id int,
    ship_date date,
    foreign key(order_no)references orders(order_no),
    foreign key(warehouse_id)references warehouse(warehouse_id));
Query OK, 0 row affected (0.292 sec)

desc shipment;

/* Inserts Values To The CUSTOMER Table */
INSERT INTO customer (cust_id, cnmae, city) VALUES (101, 'Asim', 'Gulbarga');
INSERT INTO customer (cust_id, cnmae, city) VALUES (102, 'Amir', 'Delhi');
INSERT INTO customer (cust_id, cnmae, city) VALUES (103, 'Mohsin', 'Mumbai');
INSERT INTO customer (cust_id, cnmae, city) VALUES (104, 'Yaseen', 'Bangalore');
INSERT INTO customer (cust_id, cnmae, city) VALUES (105, 'Aejaz', 'Chennai');

select * from customer;

/* Inserts Values To The ORDERS Table */
INSERT INTO orders (order_no, odate, cust_id, ord_amt) VALUES ('201', '2020-03-08', '101', '5000');
INSERT INTO orders (order_no, odate, cust_id, ord_amt) VALUES ('202', '2020-03-20', '102', '1250');
INSERT INTO orders (order_no, odate, cust_id, ord_amt) VALUES ('203', '2020-04-12', '103', '1549');
INSERT INTO orders (order_no, odate, cust_id, ord_amt) VALUES ('204', '2020-03-06', '104', '2500');
INSERT INTO orders (order_no, odate, cust_id, ord_amt) VALUES ('205', '2020-04-04', '105', '4000');

select * from orders;

/* Inserts Values To The ITEM Table */
INSERT INTO item (item_id, price) VALUES ('301', '2500');
INSERT INTO item (item_id, price) VALUES ('302', '1250');
INSERT INTO item (item_id, price) VALUES ('303', '5200');
INSERT INTO item (item_id, price) VALUES ('304', '8751');
INSERT INTO item (item_id, price) VALUES ('305', '4512');

select * from item;

/* Inserts Values To The ORDER_ITEM Table */
INSERT INTO order_item (order_no, item_id, qty) VALUES ('201', '301', '2');
INSERT INTO order_item (order_no, item_id, qty) VALUES ('202', '302', '1');
INSERT INTO order_item (order_no, item_id, qty) VALUES ('203', '303', '3');
INSERT INTO order_item (order_no, item_id, qty) VALUES ('204', '304', '2');
INSERT INTO order_item (order_no, item_id, qty) VALUES ('205', '305', '1');

select * from order_item;

/* Inserts Values To The WAREHOUSE Table */
INSERT INTO warehouse (warehouse_id, city) VALUES ('501', 'Bangalore');
INSERT INTO warehouse (warehouse_id, city) VALUES ('502', 'Gulbarga');
INSERT INTO warehouse (warehouse_id, city) VALUES ('503', 'Mumbai');
INSERT INTO warehouse (warehouse_id, city) VALUES ('504', 'Delhi');
INSERT INTO warehouse (warehouse_id, city) VALUES ('505', 'Chennai');

select * from warehouse;


/* Inserts Values To The SHIPMENT Table */
INSERT INTO shipment (order_no, warehouse_id, ship_date) VALUES ('201', '501', '2020-03-10');
INSERT INTO shipment (order_no, warehouse_id, ship_date) VALUES ('202', '502', '2020-04-08');
INSERT INTO shipment (order_no, warehouse_id, ship_date) VALUES ('203', '503', '2020-03-24');
INSERT INTO shipment (order_no, warehouse_id, ship_date) VALUES ('204', '504', '2020-04-25');
INSERT INTO shipment (order_no, warehouse_id, ship_date) VALUES ('205', '505', '2020-02-26');

select * from shipment;

/******************************* QUERIES *******************************/


/* 01.	Produce a listing: CUSTNAME, #oforders, AVG_ORDER_AMT, where the middle column is the total numbers of orders by the customer and the last column is the average order amount for that customer. */
select C.cnmae,count(order_no) as No_Of_Orders,avg(ord_amt) as Avg_Amount
from customer C,orders O
where C.cust_id = O.cust_id
group by C.cnmae;

/* 02.	List the order# for orders that were shipped from all warehouses that the company has in a specific city. */
select order_no from orders where order_no in
(select order_no from shipment 
where warehouse_id in
(select warehouse_id from warehouse 
where city = 'Bangalore'));

/* 03.	Demonstrate how you delete item# 10 from the ITEM table and make that field null in the ORDER_ITEM table. */
select * from item;
delete from item where item_id = 301;
select * from item;
select * from order_item;

commit;
Query OK, 0 rows affected (0.000 sec)
