# Calculator

A simple pet-project created to study OOP

## Installation

Go to the files folder and enter:

```bash
g++ main.cpp calc.cpp -o calculator
```

Then run it:
```bash
./calculator
```

## Usage

Just write any expression you want
```
Hello and welcome to the calculator!
Write any expression using "+", "-", "/" or "*" with positive integers: 2 + 2 * 2
8
That's your answer! Do you want to try another one [y/n]? 
```
>  **Note:** There is no operator precedence. Operations are evaluated strictly from left to right, so `2 + 2 * 2` will produce `8`, not `6`.

## License

[MIT](https://choosealicense.com/licenses/mit/)
