#include <iostream>
#include <map>

struct MyStruct
{
    int i;
    std::string s;
};

MyStruct GetStruct()
{
    return MyStruct{28, "MyString"};
}

void MapExample()
{
    std::map <std::string, int> cityTemperatures = {
        {"Moscow",  13},
        {"London",  23},
        {"Milan",  26}
    };

    // We can iterate map and dont use the first/second fields from std::pair.
    // We can name the key and value with appropriate names.
    for(const auto& [city, temperature] : cityTemperatures)
    {
        std::cout << city << ": " << temperature << std::endl;
    }
}

int main()
{
    std::cout << "Chapter 1 - Structured Bindings" << std::endl;

    // Structured bindings allow initialize multiple entities that are members of object.
    // If the editor is not recognizing structured bindings syntax, set your C++ standard in C++ extention:
    // https://stackoverflow.com/questions/49397233/how-to-enable-c17-support-in-vscode-c-extension
    auto [id, string] = GetStruct();
    std::cout << id << " " << string << std::endl;

    MapExample();

    return 0;
}