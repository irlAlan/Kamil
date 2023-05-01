#include <Kamil/Utils/Stack.h>

namespace Command{

    template<typename T>
    Stack<T>::Stack(int max_size) : max_size{max_size}
    {}

    template<typename T>
    int Stack<T>::getMax()const{return max_size;}

    template<typename T>
    int Stack<T>::push(T value){
      if(!value){
        std::cout << "No data in value passed in\n";
        return -1;
      }
      SP -=1;
      SP_pos -= 1;
      *SP = value;
      return 0;
    }

    template<>
    int Stack<std::string>::push(std::string value){
      if(value.empty()){
        std::cout << "No data in value passed in\n";
        return -1;
      }
      SP -=1;
      SP_pos -= 1;
      *SP = value;
      return 0;
    }


    template<typename T>
    int Stack<T>::pop(){
      if(SP_pos > max_size){
        std::cout << "Cannot pop anything off\n";
        return -1;
      }
      *SP = (T)0;
      SP += 1;
      SP_pos += 1;
      return 0;
    }

    template<typename T>
    void Stack<T>::printStack()const{
      for(int i{0}; i < max_size; i++){
        std::cout << stack_array[i] << ' ';
      }
      std::cout << '\n';
    }

    template<typename T>
    void Stack<T>::extend(int val){
        int oldVal{max_size};
        max_size += val;
        T* tmpStackArr{new T[max_size]};
        for(int i{0}; i < oldVal; i++){
            tmpStackArr[i] = stack_array[i];
        }
        delete[] stack_array;

        for(int i{0}; i < max_size; i++){
            stack_array[i] = tmpStackArr[i];
        }

        for(int i{oldVal}; oldVal < max_size; oldVal++){
            stack_array[i] = 0;
        }
    }

} // Command
