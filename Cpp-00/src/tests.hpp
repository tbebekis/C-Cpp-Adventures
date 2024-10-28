#ifndef TESTS_H
#define TESTS_H

#include <string>

namespace project
{

    class Man
    {
    public:
        Man() {}

        virtual std::string Say();

        static void Test();
    };

    class Greek : public Man
    {
    public:
        Greek() {}
        ~Greek();

        std::string Say();
    };
}
#endif