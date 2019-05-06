# Can you feel it?
Алгоритм работы программы.
1. К нам поступает на вход один файл с последовательно расположенными фигурками тетрамино.
  Поле каждой фигурки имеет размер 4х4 символа + символ перевода строки.
  Поля фигурок разделены пустой строкой.
  После последней фигурки не должно быть пустой строки.
2. Производим считывание карты тетрамино в буфер размером ((4 х (4 символа + '\n')) + '\n') = 21 байт (на этом этапе нужно добавить проверку на последнюю карту, чтобы не было пустой строки в конце). Командой strsplit переводим в двумерный массив char текущую карту.<br>
3. Прозводим валидацию карты, путем подсчета строк и столбцов, а также количества '#' (в фигурке тетрамино должно быть ровно 4 символа).<br>
  Если первая валидация прошла, выполняем валидацию правильной формы фигурки. Количество соприказающихся сторон у точек тетрамино - 6 или 8 (для тетрамино O). <a href="https://github.com/go0h/fillit/blob/master/tetraminos">Правильные формы фигурок.<a><br>
4. Далее для более удобного хранения и дальнейших операций с фигуркой обрезаем карту размером 4х4 до размеров тетрамино.
  Вычисляем крайние координаты '#' (x_last - x_first + 1, y_last - y_first + 1). Создаем двумерный массив char и переносим туда фигурку тетрамино, не забывая очистить старый массив.<br>
5. В качестве структуры данных используется связный список со следующими полями (некоторые из них лишние):
  - figure - двумерный массив char тетрамино;
  - width, height.
  - координаты x, y размешения при успешном размещения фигурок.
  После считывания, валидации и обрезки фигурки тетрамино, помещаем в конец списка текущую ноду с заполненными полями. После успешного чтения и создания списка, проходим по всему списку и заменяем '#' в фигурке тетрамино на 'A' для первого элемента, 'B' для второго и т.д., это нужно по заданию для правильного отображения карты.<br>
6. Перед размещением тетрамино в квадрате, в зависимости от количества фигур, считаем минимальную начальную сторону квадрата, по формуле проверенной временем: (4 * кол-во тетрамино)^0.5. Далее создаем карту (двумерный массив) и заполняем его точками.<br>
7. Запускаем рекурсивную функцию, которая берет первый тетрамино, размещает (наносит на карту) его в первой пустой клетке карты, вызывает саму себя, куда передает текущую карту и следующую ноду связного списка и т.д. Если в каком-то моменте не получается разместить фигуру на карте, функция возвращает 0, и предыдущий тетрамино стирается с карты и смещается на следующую пустую клетку. Если после перебора всех возможных вариантов размещения тетрамино, не получается разместить все фигуры, пересоздаем карту с увеличенным на 1 размером стороны и запускаем рекурсию снова. Условие выхода из рекурсии при успешном размещении тетрамино, когда node->next = NULL.
8. После успешного размещения всех фигурок тетрамино печатаем карту в стандартный вывод с рамещенными фигурками, не забывая освободить карту и связный список.