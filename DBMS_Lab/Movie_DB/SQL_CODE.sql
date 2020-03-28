create database m_movie;
Database created.

use m_movie;
Database changed.

create table actor(act_id int,
act_name varchar(20),
act_gender varchar(1),
primary key(act_id));
Table created.

create table director(
dir_id int,
dir_name varchar(20),
dir_phone varchar(10),
primary key(dir_id));
Table created.

create table movies(
mov_id int,
mov_title varchar(20),
mov_year varchar(5),
mov_lang varchar(20),
dir_id int,
primary key(mov_id),
foreign key(dir_id) references director(dir_id));
Table created.

create table movie_cast(
act_id int,
mov_id int,
role varchar(20),
foreign key(act_id) references actor(act_id),
foreign key(mov_id) references movies(mov_id));
Table created.

create table rating(
mov_id int,
rev_stars int,
foreign key(mov_id) references movies(mov_id));
Table created.

INSERT INTO actor (act_id, act_name, act_gender) VALUES ('101', 'Varun Dhavan', 'M');
INSERT INTO actor (act_id, act_name, act_gender) VALUES ('102', 'shraddha kapoor', 'F');
INSERT INTO actor (act_id, act_name, act_gender) VALUES ('103', 'Shahid', 'M');
INSERT INTO actor (act_id, act_name, act_gender) VALUES ('104', 'Akshay', 'M');
INSERT INTO actor (act_id, act_name, act_gender) VALUES ('105', 'Deepika', 'F');
Query OK, 5 rows affected (0.001)

INSERT INTO director (dir_id, dir_name, dir_phone) VALUES ('11', 'Karan ', '8987565412');
INSERT INTO director (dir_id, dir_name, dir_phone) VALUES ('12', 'HitchCock', '7865254589');
INSERT INTO director (dir_id, dir_name, dir_phone) VALUES ('13', 'Rajamouli ', '9768483512');
INSERT INTO director (dir_id, dir_name, dir_phone) VALUES ('14', 'Remo ', '8987565412');
INSERT INTO director (dir_id, dir_name, dir_phone) VALUES ('15', 'steven splielberg ', '9868483512');
Query OK, 5 rows affected (0.001)

INSERT INTO movies (mov_id, mov_title, mov_year, mov_lang, dir_id) VALUES ('1001', 'Street Dancers', '2020-01-20', 'English', '14');
INSERT INTO movies (mov_id, mov_title, mov_year, mov_lang, dir_id) VALUES ('1002', 'Bahubali', '2015-03-31', 'Telagu', '13');
INSERT INTO movies (mov_id, mov_title, mov_year, mov_lang, dir_id) VALUES ('1003', 'War House', '1999-01-03', 'English', '12');
INSERT INTO movies (mov_id, mov_title, mov_year, mov_lang, dir_id) VALUES ('1004', 'Akash', '2008-11-04', 'Kannada', '11');
INSERT INTO movies (mov_id, mov_title, mov_year, mov_lang, dir_id) VALUES ('1005', 'Street Dancers', '2020-01-20', 'Hindi', '15');
Query OK, 5 rows affected (0.001)

INSERT INTO movie_cast (act_id, mov_id, role) VALUES ('101', '1001', 'Hero');
INSERT INTO movie_cast (act_id, mov_id, role) VALUES ('102', '1002', 'Heroine');
INSERT INTO movie_cast (act_id, mov_id, role) VALUES ('103', '1003', 'Hero');
INSERT INTO movie_cast (act_id, mov_id, role) VALUES ('104', '1004', 'Hero');
INSERT INTO movie_cast (act_id, mov_id, role) VALUES ('101', '1005', 'Hero');
Query OK, 5 rows affected (0.064)

INSERT INTO rating (mov_id, rev_stars) VALUES ('1001', '5');
INSERT INTO rating (mov_id, rev_stars) VALUES ('1002', '1');
INSERT INTO rating (mov_id, rev_stars) VALUES ('1003', '4');
INSERT INTO rating (mov_id, rev_stars) VALUES ('1004', '2');
INSERT INTO rating (mov_id, rev_stars) VALUES ('1005', '3');
Query OK, 5 rows affected (0.082)
