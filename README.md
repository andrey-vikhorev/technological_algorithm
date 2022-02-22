# Технологический алгоритм

Консольное приложение реализует расчёт произвольного технологического алгоритма из булевых функций. Для приложения разработан технологический алгоритм бегущая единица.

Схема исполняемого технологического алгоритма и начальное состояние его переменных
задаються в конфигурационных файлах текстового формата, имена которых
передаются в командной строке запуска программы:

<prog_name [-n NUM] code_file_name vars_file_name.>

Также, посредством ключа “-n”, в командную строку передаётся параметр, отвечающий за количество итерация расчётной схемы.

## Схема файла содержащего алгоритм.
| Номер функции | Номер переменной 1 | Номер переменной 2 | Номер результирующей переменной |  
| ------------- |:------------------:| ------------------:| ------------------------------- |
|       5       |          1         |         3          |               5                 |
## Файл состояния переменных.
В файле через пробел перечисляються по порядку все значения переменных алгоритма. 
