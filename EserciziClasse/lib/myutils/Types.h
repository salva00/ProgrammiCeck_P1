//
// Created by Salvatore Bramante on 10/06/21.
//

#ifndef TYPES_H
#define TYPES_H
#include <iostream>
#include <utility>

namespace myutils {



    enum class Types {
        VOID,
        INT,
        FLOAT,
        STRING,
        DOUBLE,
        BOOL,
        CHAR,
    };
    typedef Types t;


    class Type {
    public:
        virtual Types getType() = 0;
        virtual std::string getStringValue()= 0;
        // virtual void setValue(Types value) = 0;
    };



    struct Instance {
        Instance(std::string nameI,Type* valueI):name(std::move(nameI)),value(valueI){}
        std::string name;
        Type* value{};
    };

    class Int : public Type {
    public:
        Int(int value) { this->value = value; }
        virtual Types getType() { return Types::INT; }
        virtual std::string getStringValue(){};
        int getValue() { return value; }
        void setValue(int value) { this->value = value; }
    private:
        int value;
    };

    class Double : public Type {
    public:
        Double(double value) { this->value = value; }
        virtual Types getType() { return Types::DOUBLE; }
        int getValue() { return value; }
        void setValue(double value) { this->value = value; }
        virtual std::string getStringValue(){};

    private:
        double value;
    };

    class Float : public Type {
    public:
        Float(float value) { this->value = value; }
        virtual Types getType() { return Types::FLOAT; }
        int getValue() { return value; }
        void setValue(float value) { this->value = value; }
        virtual std::string getStringValue(){};

    private:
        float value;
    };

    class String : public Type {
    public:
        String(std::string value) { this->value = value; }
        virtual Types getType() { return Types::STRING; }
        virtual std::string getStringValue(){return value;};
        std::string getValue() { return value; }
        void setValue(std::string value) { this->value = value; }
    private:
        std::string value;
    };

    class Bool : public Type {
    public:
        Bool(bool value) { this->value = value; }
        virtual Types getType() { return Types::BOOL; }
        bool getValue() { return value; }
        void setValue(bool value) { this->value = value; }
        virtual std::string getStringValue(){};
    private:
        bool value;
    };

    class Char : public Type {
    public:
        Char(char value) { this->value = value; }
        virtual Types getType() { return Types::CHAR; }
        char getValue() { return value; }
        void setValue(char value) { this->value = value; }
        virtual std::string getStringValue(){};

    private:
        char value;
    };
};
#endif //SORTHEAP_TYPES_H
