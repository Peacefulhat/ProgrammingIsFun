#### Create database
- CREATE DATABASE {data_base_name};
#### Show databases
- show databases; shows all the database
#### Select a particular database
- USE {data_base_name};
#### Create a table
- CREATE TABLE(COLUMN 1 TYPE 1, COLUMN 2, TYPE 2, COLUMN 3, TYPE 3,...);
#### Insert a value in a table.
- INSERT INTO {table_name} VALUES(first row value,second row value,...);
#### Show tables
- show tables; list all tables in a selected database.

[SQL DATA TYPES] (https://www.w3schools.com/sql/sql_datatypes.asp)

#### Advanced data types
1) json: java script object notation.

#### Types of commands
- Types of SQL commands:
##### DDL
- Defines the relation schema.

- CREATE:: create table, db ,view.
- ALTER TABLE :: remove all the tuples from the table.
- RENAME :: rename db name, table name, column name etc.
- TRUNCATE :: remove all the tuple form the table.
##### DRL/DQL (data retrieval language/ data query language)
- retrieve the data from the table.

- SELECT 
##### DML(data modification language)	
- use to perform modification in the DB.

- INSERT :: insert data into a relation.
- UPDATE :: update relation data.
- DELETE :: delete row(s) from the relation.
##### DCL (data control language)
- grant to revoke authorities from user.
 
- GRANT :: access privileges to the DB.
- REVOKE :: revoke user access privileges.
##### TCL (transaction control language)
- to manage transactions done in the db.

- START TRANSACTION :: begin a transaction.
- COMMIT :: apply all the changes and end transaction.
- ROLLBACK :: discard changes and end transaction
- SAVEPOINT :: check out within the group of transactions in which to rollback.

#### DQL:
- what we need db.
- and some relations(tables) to work with.
#### Select
- SELECT :: {set of column name} from {table_name};
- order of execution, from right to left.
- Q:: can we use select key word without from clause.
	- yes using DUAL Tables.
	- Dual tables created by My SQL help user to do certain obvious actions without referring to user defined tables.
	- example: SELECT 44+11; Will return 55, in a tabular format.
	- SELECT now();
	- SELECT UCASE(); etc.
#### Where
- Reduces row based on given conditions.
- Example: SELECT * FROM Customer WHERE AGE>=18;

#### Between
- SELECT * FROM Customer WHERE AGE BETWEEN 0 AND 100;
- in the above example 0 and 100 are inclusive.
#### IN
- Reduces the OR Conditions
- Select * from worker where department = 'Hr' or department ="admin" ...
- there is a better way to this.

- select * from worker where department in {'Hr','admin',...};

#### AND/OR/NOT
- AND :: WHERE cond1 AND cond2
- OR  :: WHERE cond1 OR cond2
- NOT :: WHERE col_name NOT IN ("hr","admin");

#### IS NULL
- select * from customer where prime_status IS NULL;

#### Pattern Searching / Wildcard('%', {underscore})
- with like key word.
- %: show any no of character 
- underscore: only one character.
- select * from customer where name like %p_. 
- it will print name whose 2nd last character is p.

#### Sorting
- sort the data in ascending order/descending order.
- example:
- select * from  worker ORDER BY Salary ASC;
- by default ascending.
- ASC :: for ascending.
- DESC :: for descending.
#### Distinct
- example:
- select distinct department from Workers;
#### Data Grouping
-  
