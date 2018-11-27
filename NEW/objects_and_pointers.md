# Классы, объекты и указатели

* После описания класса в отдельных файлах (.h, .cpp) мы имеем возможность создания объектов (экземпляров) данного класса.

### Способ 1

* Создание объекта без указателей

```C
Node a(10);
```

* a - переменная, которая содержит в себе непосредственно объект типа Node

Обращение к членам класса в таком случае имеет тривиальный вид:

```
cout << a.getValue();
```

### Способ второй

* Создание "объектных переменных", то есть таких ссылочных переменных, которые содержат только адрес реального объекта

```C
Node *a = new Node(10);
```

* a - ссылка на объект типа Node

Обращение к членам класса в таком случае имеет вид:

```C
cout << (*a).getValue();
```

* В данном случае *a позволяет получить реальный объект по ссылке a.

Можно упростить запись:

```C
cout << a->getValue();
```

Какой способ предпочтительнее?

Конечно второй, потому что подобный подход используется в Java/C# в неявном виде.

## Листинг 1

```C
// a - указатель на объект типа Node
    // содержит адрес объекта Node
    Node *a = new Node(5);
    cout << a << endl;

    Node notPointerNode(10);
    Node *b = &notPointerNode;
    cout << b << endl;
    cout << notPointerNode.getValue() << endl;
    cout << (*b).getValue() << endl;
    cout << b->getValue() << endl;
    return 0;
```


