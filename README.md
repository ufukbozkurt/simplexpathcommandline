Very Simple XPath Command Line Tool

XPath command line query tool, written in C and dependent to libxml2. "makefile" may need to be modified for different library locations.
It includes example data under "data" folder. 

```bash
make&&make clean

./sXPath data/example.xml

EXPRESSION: /bookstore/book[price>25.00]/author       
RESULT:
Zülfü Livaneli

EXPRESSION: //book
RESULT:
<title lang="en">The Call Of The Wild</title>
<title lang="tr">Serenat</title>

EXPRESSION: :QUIT

```

Note that, xpath expressions should always start with "/" or "//".
