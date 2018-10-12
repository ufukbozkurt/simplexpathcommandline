## Very Simple XPath Command Line Tool

XPath command line query tool, written in C and dependent to libxml2. "makefile" may need to be modified for different library locations.
It includes example data under "data" folder. 

```bash
make&&make clean

./sXPath data/example.xml

EXPRESSION: /bookstore/book[price>25.00]/author
RESULT:
<author>Zülfü Livaneli</author>

EXPRESSION: //book
RESULT:
<book>
  <title lang="en">The Call Of The Wild</title>
  <author>Jack London</author>
  <price>13.52</price>
</book>
<book>
  <title lang="tr">Serenat</title>
  <author>Zülfü Livaneli</author>
  <price>25.08</price>
</book>

EXPRESSION: :QUIT

```

Note that, xpath expressions should always start with "/" or "//".
