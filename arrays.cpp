#include <iostream>
#include <stdexcept>
#include <string>

template <typename T> class Array {
private:
  int len = 0;       // la longitud que el usuario cree que tiene el arreglo
  int capacidad = 0; // la capacidad del arreglo
  T *arr;

public:
  // Constructor -> default 16 elementos
  Array() { this->arr = (T *)new T[16]; }
  // Constructor -> usuario pasa capacidad
  Array(int capacidad) {
    if (capacidad < 0) {
      throw std::invalid_argument("Illegal capacity");
    }
    this->capacidad = capacidad;
    this->len = capacidad;
    this->arr = (T *)new T[capacidad];
  }
  // Retorna longitud del arreglo
  int size() { return len; }
  // Retorna si el arreglo esta vacio
  bool isEmpty() { return size() == 0; }

  // Retorna el elemento en n index
  T get(int index) { return arr[index]; }
  // Pone un elemento en n index
  void Set(int index, T element) { arr[index] = element; }

  // Limpia nuestro arreglo
  void clear() {
    for (int i = 0; i < capacidad; i++) {
      arr[i] = NULL;
    }
    len = 0;
  }

  // Añade elemento redimensionando el arreglo(el arreglo se duplica cada vez
  // que necesita -> capacidad*2)
  void add(T element) {
    if (len + 1 >= capacidad) {
      if (capacidad == 0)
        capacidad = 1;
      else
        capacidad *= 2;
      T *newArr = (T *)new T[capacidad];
      for (int i = 0; i < len; ++i) {
        newArr[i] = this->arr[i];
      }
      this->arr = newArr;
      delete newArr;
    }
    this->arr[len++] = element;
  }

  // Retorna el elemento que buscamos en indice y crea un nuevo arreglo sin ese
  // elemento
  T removeAt(int rmIindex) {
    if (rmIindex >= len && rmIindex < 0)
      throw std::out_of_range("Out of range");
    T data = this->arr[rmIindex];
    T newArr[] = (T[]) new T[len - 1];
    for (int i = 0, j = 0; i < len; i++, j++) {
      if (i == rmIindex) {
        j--;
      } else
        newArr[j] = this->arr[i];
    }
    delete newArr;
    this->arr = newArr;
    capacidad = --len;
    return data;
  }
  // Remueve un elemento
  bool remove(T element) {
    for (int i = 0; i < len; ++i) {
      if (this->arr[i] == element) {
        removeAt(i);
        return true;
      }
    }
    return false;
  }
  // Retorna el indice de un elemento, si no existe retorna -1
  int indexOf(T element) {
    for (int i = 0; i < len; ++i) {
      if (this->arr[i] == element) {
        return i;
      }
    }
    return -1;
  }
  // Retorna si existe el elemento
  bool contains(T element) { return indexOf(element) != -1; }

  // Convierte el arreglo a un string
  std::string toString() {
    if (len == 0)
      return "[]";
    else {
      std::string newstring = "";
      newstring.append("[");
      for (int i = 0; i < len - 1; ++i) {
        newstring.append(arr[i] + ", ");
      }
      return newstring.append(arr[len - 1] + "]");
    }
  }
};

int main() {
  Array<int> myArray(18);
  std::cout << myArray.size() << std::endl;
  for (int i = 0; i < myArray.size(); ++i) {
    myArray.add(i);
  }
  for (int i = 0; i < myArray.size(); ++i) {
    std::cout << myArray.get(i) << std::endl;
  }
}
