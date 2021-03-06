# std::vector
### Краткое пособие для участников коллоквиума (для общего развития)
[в коллоквиуме это вам не нужно]

####Причины любить вектор:
1. О **выделении памяти** позаботились за вас:
  * Массив:

  ```c++
  int* A = new int[n];
  ...//здесь мы заполняем массив и место заканчивается
  int* B = new int[2*n];
  ...//переносим содержимое A в B
  delete A;//очищаем память
  A = B;//не факт, что сработает
  ```
  * Вектор:

  ```c++
  vector<int> A(n);
  ...//заполняем вектор, место вновь заканчивается
  A.push_back(someInt);//добавляем ещё один элемент
  vector<int> B = A;//и вот так делать можно
  ```
2. Здесь всё ещё есть обращение по **индексу**:
  * Массив:

  ```c++
  int* A = new int[n];
  for (int i = 0; i < n; i++) {
    A[i] = i;
  }
  ```
  * Вектор:

  ```c++
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    A[i] = i;
  }
  ```
3. Можно обратиться к последнему элементу **не по индексу**:
  
  ```c++
  vector<int> A(n);
  ...//здесь что-то происходит, мы теряем n, либо размер меняется
  A.back();//последний элемент
  ```
  * `Причина, по которой это важно заключается в особенностях представления чисел в системе, над которой вы работаете`