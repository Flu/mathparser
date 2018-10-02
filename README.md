# MathParser
by Fluturel Adrian (c) 2018

Interpretor for mathematical expressions. Lexes, parses them and the computes them, hopefully in the right order. I hope to finally integrate this pet project with a compiler I'm in the making of. Hopefully it will prove itself up to the standards.

## Using it

Not much here. Clone the repo, navigate to src, compile with whatever (I used gcc 4.7) and I suggest using it with the interactive shell, like so:

```bash
git clone git@github.com:Flu/mathparser.git
cd math-parser
g++ --std=c++17 parser.cpp -o math-parser.o
./math-parser.o --interactive
```

You can figure out the next steps from there.
