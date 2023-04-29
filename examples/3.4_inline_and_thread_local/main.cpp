#include <thread>
#include <iostream>

#include "MyClass.hpp"

/* Program stdout

Chapter 3.4 - Inline and thread local storage

main() begin:
- gName: global
- tName: tls
- lName: local
main() later:
- gName: thread1 name
- tName: thread1 name
- lName: thread1 name
foo() begin:
- gName: thread1 name
- tName: tls
- lName: local
foo() end:
- gName: thread2 name
- tName: thread2 name
- lName: thread2 name
main() end:
- gName: thread2 name
- tName: thread1 name
- lName: thread1 name

*/

void foo()
{
    myThreadData.print("foo() begin:");
    myThreadData.gName = "thread2 name";
    myThreadData.tName = "thread2 name";
    myThreadData.lName = "thread2 name";
    myThreadData.print("foo() end:");
}

int main()
{
    std::cout << "Chapter 3.4 - Inline and thread local storage" << std::endl;

    myThreadData.print("main() begin:");

    myThreadData.gName = "thread1 name";
    myThreadData.tName = "thread1 name";
    myThreadData.lName = "thread1 name";

    myThreadData.print("main() later:");

    std::thread t(foo);
    t.join();

    myThreadData.print("main() end:");

    return 0;
}
