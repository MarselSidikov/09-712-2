# Бинарные файлы

## Считывание из обычного текстового файла

```C
    UniversityEmployee employers[6];
    int i = 0;
    while(!input.eof()) {
        input >> employers[i].age
              >> employers[i].name
              >> employers[i].department
              >> employers[i].is_teacher;
        i++;
    }
```

## Запись в обычный текстовый файл

```C
	ofstream output("C:\\Users\\admin.WIN-IPM3OA3VQNQ\\ClionProjects\\BinaryFiles\\employers.txt", ios_base::app);
    output << employee.age <<
           " " << employee.name <<
           " " << employee.department <<
           " " << employee.is_teacher << endl;
    output.close();
```

## Запись в Бинарный файл

```C
    ofstream bin_output("C:\\Users\\admin.WIN-IPM3OA3VQNQ\\ClionProjects\\BinaryFiles\\employers.bin", ios::out|ios::binary);
    bin_output.write((char*)&employers, sizeof(empoyers);
    bin_output.close();
```

## Считать из бинарного файла

```C
    UniversityEmployee employers[6];
    ifstream bin_input("C:\\Users\\admin.WIN-IPM3OA3VQNQ\\ClionProjects\\BinaryFiles\\employers.bin", ios::in|ios::binary);
    bin_input.read((char*)&employers, sizeof(employers));
    bin_input.close();
```