//********************************************************
// The following code example is taken from the book
//  C++17 - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppstd17.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************


#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <iostream>
#include <string>

class Node
{
  private:
    std::string value;
    std::vector<Node> children;  // OK since C++17 (Node is an incomplete type here)
  public:
    // create Node with value:
    Node(std::string s) : value{std::move(s)}, children{} {
    }

    // add child node:
    void add(Node n) {
      children.push_back(std::move(n));
    }

    // access child node:
    Node& operator[](std::size_t idx) {
      return children.at(idx);
    }

    // print node tree recursively:
    void print(int indent = 0) const {
      std::cout << std::string(indent, ' ') << value << '\n';
      for (const auto& n : children) {
        n.print(indent+2);
      }
    }
    //...
};

#endif // NODE_HPP

