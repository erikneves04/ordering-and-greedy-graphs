# Graph Coloring Verification and Vertex Sorting Project

## Project Description

This C++ project aims to verify if a given coloring for a specific graph is greedy. Additionally, it provides the functionality to sort the graph vertices using various sorting methods. The available sorting methods include Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, Merge Sort, Heap Sort, and a custom sorting method.

## Execution Instructions

To run the program, use the following command in the Linux environment:

<code>./bin/tp2.out</code>

The program collects graph data from the standard input.

## Sorting Methods

The available sorting methods are selected through the option provided during program execution. The options and corresponding methods are:

- **'b'**: Bubble Sort
- **'s'**: Selection Sort
- **'i'**: Insertion Sort
- **'q'**: Quick Sort
- **'m'**: Merge Sort
- **'p'**: Heap Sort
- **'y'**: Custom Sort

## How to Select the Sorting Method

When running the program, you will be prompted to enter the option corresponding to the desired sorting method. If an invalid option is provided, the program will throw an exception (`invalid_orderer_option_exception`).

## Compilation

The source code can be compiled using a C++ compiler. It is recommended to use the GNU g++ compiler with the following command:

`Make`

## License

This project is distributed under the [MIT license](LICENSE).
