# Руководство по фреймворку для тестов.
### Для тестировщиков, которые должны их писать.
> Собственно, разберём на примере уже имеющегося. Что тут ещё писать?

```c++
#include "../structs/struct.h"
/* Разнообразные инклюды */
TEST_CASE ( "Натуральные числа", "[natural]" ) {  // Название теста
    #ifdef COM_NN_D_CPP  // Название тестируемого файла как в гардах
    SECTION ( "COM_NN_D [сравнение]" ) {  // Название секции тестов
        /* Необходимые действия */

        REQUIRE( %логическое выражение% );
        // Засчитано, если выражение истинно

        REQUIRE_FALSE( %логическое выражение% );
        // Засчитано, если выражение ложно

        INFO( "Значение i " << i );
        // Сохраняет сообщение при тестировании

        WARN( %сообщение% );
        // Выводит сообщение при тестировании

        FAIL( %сообщение% );
        // Выводит сообщение и прерывает тест

    }
    #endif  // COM_NN_D_CPP
}
```

### И это всё...