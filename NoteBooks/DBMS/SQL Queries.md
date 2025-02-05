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
#### Data Grouping(Group by)
- The `GROUP BY` statement groups rows that have the same values into summary rows, like "find the number of customers in each country"
- table get rearranged internally.

- GROUP BY clause is used to collect data from multiple records and group the result by one or more columns. it is generally use in a select statement. 
- Groups into category based on column given.
- SELECT c1,c2,c3 from sample_table where cond GROUP BY c1,c2,c3.
- All the column names mentioned after SELECT statement shall be repeated in GROUP BY in order to successfully execute the query.

- Generally used with aggregation functions to perform various actions.
- An aggregate function is a function that performs a calculation on a set of values, and returns a single value.
- Aggregate functions are often used with the `GROUP BY` clause of the `SELECT` statement. The `GROUP BY` clause splits the result-set into groups of values and the aggregate function can be used to return a single value for each group.
- COUNT()
- SUM()
- AVG()
- MIN()
- MAX()

- Aggregate functions ignore null values (except for `COUNT()`).

#### Distinct
- finds the distinct value in a table.
- example:
- select distinct (column_name) from Workers;
- GROUP BY can also be used for the same .
	- select (column_name) form table GROUP BY column_name; same output as above DISTINCT query.
	- SQL is smart enough to realize that if you are using GROUP BY and not using any aggregation function, then you mean DISTINCT.

#### GROUP BY HAVING
- Out of the categories made by GROUP BY, we would like to know only particular thing (cond).
- Similar to WHERE.
- Select COUNT(cust_id), country from customer GROUP BY country HAVING COUNT(cust_id) > 50;
- WHERE vs HAVING
- Both have same function of filtering the row base on certain conditions.
- WHERE clause is used to filter the rows from the table based on specified condition
- HAVING clause is used to filter the rows from the groups based on the specified condition.
- HAVING is used after GROUP BY while WHERE is used before GROUP BY clause.
- If you are using HAVING, GROUP BY is necessary.
- WHERE can be used with SELECT, UPDATE & DELETE keywords while GROUP BY used with SELECT.

#### Constraints (DDL)
##### Primary Key:
- PK is not null and unique and only one per table(only one column be primary key).
//TODO: add link to image. for primary key.(refer to notes pdf).

##### Foreign key:
- used for representing relation among tables.
- FK refers to PK of other table.
- Each relation can having any number of FK.
- CREATE TABLE ORDER(
	id INT PRIMARY KEY,
	delivery_date DATE,
	order_placed_date DATE,
	cust_id INT,
	FOREIGN KEY(cust_id)REFERENCES customer(id)	
	);
##### Unique 
- Unique , can be null ,table can have multiple unique attributes.
- CREATE TABLE customer(
	...
	email VARCHAR(1024) UNIQUE,
	...
  );
##### Check
- CREATE TABLE customer(
...

-- CONSTRAINT constraint_name CHECK (CONDITION) // this valid.

CONSTRAINT CHECK (CONDITION) // this also valid.
);

- constraint_name, can also avoid this, MySQL generate name of constraint automatically.


##### Default
- set default value of columns.