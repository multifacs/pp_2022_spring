// Copyright 2022 Tulkina Olga
#include "../../modules/task_1/tulkina_o_labeling/labeling.h"

std::vector<std::vector<int>> labeling(
    const std::vector<std::vector<int>>& binary_image) {
  int width = binary_image[0].size(),
      height = binary_image.size();  // ширина и высота изображения

  Union un(height * width + 1);
  std::vector<std::vector<int>> res(
      height, std::vector<int>(width));  // вектор результат

  for (int y = 0; y < height; y++) {  // проход по изображению
    for (int x = 0; x < width; x++) {
      if (binary_image[y][x] > 0) {  // пропустить фоновую компоненту

        int index = y * width + x + 1;  // локальное значение компоненты

        if (x > 0 && binary_image[y][x - 1]) {  // проверка идентификатора
                                                // соседней компоненты
          un.set_label(index,
                       y * width + x - 1 + 1);  // объединить две компоненты
        }
        if (y > 0 && binary_image[y - 1][x]) {  // проверка идентификатора
                                                // соседней компоненты
          un.set_label(index,
                       (y - 1) * width + x + 1);  // объединить две компоненты
        }
        if ((y > 0 && x > 0) &&
            binary_image[y - 1][x - 1]) {  // проверка идентификатора соседней
                                           // компоненты
          un.set_label(index, (y - 1) * width + (x - 1) +
                                  1);  // объединить две компоненты
        }
        if ((y > 0 && x < width - 1) &&
            binary_image[y - 1][x + 1]) {  // проверка идентификатора соседней
                                           // компоненты
          un.set_label(index, (y - 1) * width + (x + 1) +
                                  1);  // объединить две компоненты
        }
      }
    }
  }

  for (int y = 0; y < height; y++) {  // маркировка
    for (int x = 0; x < width; x++) {
      if (binary_image[y][x] > 0) res[y][x] = un.get_label(y * width + x + 1);
    }
  }
  return res;
}
