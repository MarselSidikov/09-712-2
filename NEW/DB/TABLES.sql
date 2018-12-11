create table salesman (
  id   SERIAL PRIMARY KEY,
  name VARCHAR(100)
);

create table customer (
  id   SERIAL PRIMARY KEY,
  name VARCHAR(100)
);

create table "order" (
  id          SERIAL PRIMARY KEY,
  date        TIMESTAMP,
  amount      INTEGER,
  customer_id INTEGER,
  salesman_id INTEGER,
  foreign key (customer_id) references customer (id),
  foreign key (salesman_id) references salesman (id)
);

create table product (
  id    SERIAL PRIMARY KEY,
  title VARCHAR(20)
);

alter table "order"
  add column product_id integer;
alter table "order"
  add foreign key (product_id) references product (id);


select name
from salesman s
where s.id in ((select salesman_id from "order" o1 where customer_id =
                                                         (select id from customer c where c.name = 'Марсель')));

-- id покупателя с именем марсель
select id
from customer c
where c.name = 'Марсель';

-- получить всех продавцов которые обслуживали марселя
select salesman_id
from "order" o1
where customer_id =
      (select id from customer c where c.name = 'Марсель');

-- получить все названия продуктов и их количество, которые заказал Марсель

-- получим названия продуктов из таблицы order, используя таблицу product

select p.title, o.amount
from "order" o
       join product p on o.product_id = p.id
where o.customer_id in (select id from customer c where c.name = 'Марсель');