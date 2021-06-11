//
// Created by Salvatore Bramante on 10/06/21.
//

#ifndef SORTHEAP_HELPERS_H
#define SORTHEAP_HELPERS_H
#include "Types.h"

namespace myutils{

    Instance returnString(const std::string& name,const std::string& value){
        static String strObj{value};
        static Instance returnObj{name,&strObj};
        return returnObj;
    }

    Instance getCorrectType(std::ifstream& file,const std::pair<std::string,Types>& currentType){
      std::string temp;
      switch (currentType.second) {
          case Types::STRING:
              std::getline(file, temp);
              return returnString(currentType.first,temp);
              // VECTOR <3 :)
              break;
          case Types::INT:
              /*int pippo;
              file >> pippo;
              elem.value->setValue(pippo);*/
          case Types::FLOAT:
              /*float pippo1;
              file >> pippo;
              elem.value->setValue(pippo);*/
          case Types::DOUBLE:
              /*double pippo2;
              file >> pippo;
              elem.value->setValue(pippo);*/
          case Types::BOOL:
              /*bool pippo;
              file >> pippo3;
              elem.value->setValue(pippo);*/
          case Types::CHAR:
              /*char pippo4;
              file >> pippo;
              elem.value->setValue(pippo);*/
          default:
              throw std::invalid_argument("Sei scemo");
              break;
      }
  }
};


#endif //SORTHEAP_HELPERS_H
