Лабораторная работа №4 — Музыкальные инструменты

Структура:
include/ — заголовочные файлы классов
src/     — реализации классов
tests/   — клиентская тестовая программа
data/    — исходные данные
docs/    — диаграмма PlantUML
Doxyfile — настройки генерации документации

СБОРКА НА macOS (выполнять из корня проекта):

mkdir -p build

clang++ -std=c++17 -Wall -Wextra -Iinclude -c src/MusicalInstrument.cpp -o build/MusicalInstrument.o
clang++ -std=c++17 -Wall -Wextra -Iinclude -c src/StringInstrument.cpp -o build/StringInstrument.o
clang++ -std=c++17 -Wall -Wextra -Iinclude -c src/WindInstrument.cpp -o build/WindInstrument.o
clang++ -std=c++17 -Wall -Wextra -Iinclude -c src/Guitar.cpp -o build/Guitar.o
clang++ -std=c++17 -Wall -Wextra -Iinclude -c src/Violin.cpp -o build/Violin.o
clang++ -std=c++17 -Wall -Wextra -Iinclude -c src/Flute.cpp -o build/Flute.o
clang++ -std=c++17 -Wall -Wextra -Iinclude -c src/SynthGuitar.cpp -o build/SynthGuitar.o

СТАТИЧЕСКАЯ БИБЛИОТЕКА И ТЕСТ:

ar rcs build/liblab4.a build/MusicalInstrument.o build/StringInstrument.o build/WindInstrument.o build/Guitar.o build/Violin.o build/Flute.o build/SynthGuitar.o
clang++ -std=c++17 -Wall -Wextra -Iinclude tests/client.cpp -Lbuild -llab4 -o build/test_static
./build/test_static

ДИНАМИЧЕСКАЯ БИБЛИОТЕКА И ТЕСТ:

clang++ -dynamiclib -o build/liblab4.dylib build/MusicalInstrument.o build/StringInstrument.o build/WindInstrument.o build/Guitar.o build/Violin.o build/Flute.o build/SynthGuitar.o
clang++ -std=c++17 -Wall -Wextra -Iinclude tests/client.cpp -Lbuild -llab4 -Wl,-rpath,@executable_path -o build/test_dynamic
./build/test_dynamic

ДОКУМЕНТАЦИЯ DOXYGEN:

brew install doxygen
doxygen Doxyfile

HTML-документация появится в docs/html/index.html.
Текстовая диаграмма PlantUML находится в docs/classes.puml.
