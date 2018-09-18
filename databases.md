# Базы данных

* [Ссылка 1](https://github.com/MarselSidikov/JAVA_IT_PARK_WORK_5/wiki/%2324.-DB)
* [Ссылка 2](https://github.com/MarselSidikov/JAVA_ENTERPRISE/wiki/%D0%91%D0%90%D0%97%D0%AB-%D0%94%D0%90%D0%9D%D0%9D%D0%AB%D0%A5)
* [Ссылка на установку](https://www.enterprisedb.com/downloads/postgres-postgresql-downloads)
* [Ссылка на летние вечера](http://www.sql-ex.ru/?Lang=0)

```SQL
CREATE TABLE student (
  id SERIAL PRIMARY KEY,
  name VARCHAR(30),
  age INTEGER,
  is_tatarin BOOLEAN
);

INSERT INTO student(name, age, is_tatarin)
    VALUES ('Ilgam', 19, true);

INSERT INTO student(name, age, is_tatarin)
    VALUES ('Nikita', 18, FALSE );

SELECT (name) FROM student WHERE student.age < 20;
SELECT * FROM student;

CREATE TABLE dish (
  id SERIAL PRIMARY KEY,
  title VARCHAR(30),
  owner_id INTEGER REFERENCES student(id)
);

INSERT INTO dish(title, owner_id) VALUES
  ('очпочмак', 1);
INSERT INTO dish(title, owner_id) VALUES
  ('пицца', 1);
INSERT INTO dish(title, owner_id) VALUES
  ('пивас', 1);

INSERT INTO dish(title, owner_id) VALUES
  ('манты', 2);

INSERT INTO dish(title, owner_id) VALUES
  ('окрошка', 3);

INSERT INTO dish(title, owner_id) VALUES
  ('манты', 3);

SELECT * FROM student JOIN
  dish ON student.id = dish.owner_id;

SELECT * FROM student LEFT JOIN
  dish ON student.id = dish.owner_id;

SELECT * FROM student RIGHT JOIN
  dish ON student.id = dish.owner_id;

SELECT * FROM student FULL OUTER JOIN
  dish ON student.id = dish.owner_id;
```

### Пицца

```SQL
create table client (
--   уникальное целое число, которое будет генерироваться автоматически
  id SERIAL PRIMARY KEY,
  first_name VARCHAR(30),
  last_name VARCHAR(30),
  phone VARCHAR(20)
);

create table pizza (
  id SERIAL PRIMARY KEY,
  name VARCHAR(30),
  price DOUBLE PRECISION
);

create table "order" (
  id SERIAL PRIMARY KEY,
  address VARCHAR(30),
  client_id BIGINT,
  FOREIGN KEY (client_id) REFERENCES client(id)
);

create table pizza_order (
  pizza_id BIGINT,
  order_id BIGINT,
  FOREIGN KEY (pizza_id) REFERENCES pizza(id),
  FOREIGN KEY (order_id) REFERENCES "order"(id)
);
```
