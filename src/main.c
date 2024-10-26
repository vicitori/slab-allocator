#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define count_objects_in_slab(object_size) (ceil(cache_size / (object_size)))
#define count_slab_size(object_size) \
    ((object_size) * count_objects_in_slab(object_size))
#define cache_size ((size_t)(4096))

/*
  структура аллокатора:
	memory -> caches (хранит объекты одного типа) -> slabs -> objects
*/

void *init_cache(size_t object_size) {}

void *allocate(size_t object_size) {}

int main() {
    /*
	    есть варианты:
	    - создавать много разных кэшей с разными размерами объектов
	    (если окажется, что такого кэша ещё нет, но его просят выделить)
	    - изначально, при запуске утилиты задавать размер объектов
    */
}

/*
slab -- набор одной или нескольких смежных страничек памяти
slab cache -- контейнер слэбов одного типа
generic cache -- в нём могут храниться разные объекты одного размера

как определяем размеры объектов и слэбов?
кэш задаёт размер объекта (вместе с метадатой)
у объектов 2 состояния:
 - free
 - used

у слэбов 3 состояния:
 - empty => объекты free
 - partitially =>
 - full => объекты used

просим память => смотрим на partitially slab
1. создаём кэш (фикс размер -- 4096 байт)
2. сразу же делим его на слэбы
3. сразу же помечаем слэбы как свободные (отдельный список??)
*/