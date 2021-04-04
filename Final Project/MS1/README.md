# Milestone 1

## `Utilities` and `Station` classes

Milestone 1 implements and tests the `Utilities` and `Station` modules.

- The `Utilities` module supports the parsing of input files, which contain information used to setup and configure the assembly line.
- The `Station` module manages information about a station on the assembly line, which holds a specific item and fills customer orders.

The specifications of these two modules are defined below.


### `Utilities` Module

Parsing string data from input files into tokens is performed uniformly for all objects within the simulation system.  The `Utilities` type provides the basic functionality required for all objects in the system.

The `Utilities` class has the following structure:

***Instance Variable***

-  `m_widthField` -- specifies the length of the token extracted; used for display purposes; default value is `1`.


***Class Variable***

-  `m_delimiter` -- separates the tokens in any given `std::string` object. All `Utilities` objects in the system **share the same delimiter**.


***Member Functions***

-  `void setFieldWidth(size_t newWidth)` -- sets the field width of the current object to the value of parameter `newWidth`
-  `size_t getFieldWidth() const` -- returns the field width of the current object
-  `std::string extractToken(const std::string& str, size_t& next_pos, bool& more)` -- extracts a token from string `str` referred to by the first parameter
    - This function uses the delimiter to extract the next token from `str` starting at position `next_pos`.
    - If successful, this function returns a copy of the extracted token found, updates `next_pos` with the position of the next token, and sets `more` to `true` (`false` otherwise0.
    - This function reports an exception a delimiter is found at `next_pos`.
    - This function updates the current object's `m_widthField` data member if its current value is less than the size of the token extracted.
    - **Note:**  in this application, `str` represents a single line that has been read from an input file


***Class Functions***

-  `static void setDelimiter(char newDelimiter)` -- sets the delimiter for this class to the character received
-  `static char getDelimiter()` -- returns the delimiter for this class.



### `Station` Module

A `Station` object manages a single station on the assembly line. Each station handles a specific item for filling customer orders.

The `Station` class has the following structure:

***Instance Variables***

- the id of the station (integer)
- the name of the item handled by the station (string of characters)
- the description of the station (string of characters)
- the next serial number to be assigned to an item at this station (non-negative integer)
- the number of items currently in stock (non-negative integer)


***Class Variables***

- `m_widthField` -- the maximum number of characters required to print to the screen the *item name*, *serial number* and *quantity* for any object of type `Station`.  Initial value is 0.
- `id_generator` -- a variable used to generate IDs for new instances of type `Station`. Every time a new instance is created, the current value of the `id_generator` is stored in that instance, and `id_generator` is incremented.  Initial value is 0.


***Public Functions***

-  custom 1 argument constructor
    - upon instantiation, an `Station` object receives a reference to an unmodifiable `std::string`.  This string contains a single record (one line) that has been retrieved from the input file specified by the user.
    - this constructor uses a `Utilities` object (defined locally) to extract each token from the record and populates the `Station` object accordingly.
    - this constructor assumes that the string contains 4 fields separated by the delimiter, in the following order:
        - name of the item
        - starting serial number
        - quantity in stock
        - description
    - the token delimiter is a single character, specified by the client and previously stored into the `Utilities` class of objects.
    - this constructor extracts *name*, *starting serial number*, and *quantity* from the string first
    - before extracting *description*, it updates `Station::m_widthField` to the maximum value of `Station::m_widthField` and `Utilities::m_widthField`.
        - **Note:**  the `display(...)` member function uses this field width to align the output across all the records retrieved from the file.

-  `const std::string& getItemName() const` - returns the name of the current `Station` object
-  `size_t getNextSerialNumber()` – returns the next serial number to be used on the assembly line and increments `m_serialNumber`
-  `size_t getQuantity() const` – returns the remaining quantity of items in the `Station` object
-  `void updateQuantity()` – subtracts 1 from the available quantity; should not drop below 0.
-  `void display(std::ostream& os, bool full) const` -- inserts information about the current object into stream `os`.
    - if the second parameter is `false`, this function inserts only the ID, name, and serial number in the format: `[ID] Item: NAME [SERIAL]`
    - if the second parameter if `true`, this function inserts the information in the following format: `[ID] Item NAME [SERIAL] Quantity: QTY Description: DESCRIPTION`
    - the `ID` field uses 3 characters, the `NAME` and `QTY` fields use `m_widthField` characters, the serial number field uses 6 characters; the `DESCRIPTION` has no formatting options (see the sample output for other formatting options)
    - this function terminates the printed message with an endline


## Tester Module

The tester module and the input files are included in the repository. Do not modify any of them.

## Sample Output

Look in the file `ms1_output.txt` for the command line necessary to start the application and the expected output.

#### Submission

Before the due date, upload to your matrix account the following files:
-  `Utilities.h`
-  `Utilities.cpp`
-  `Station.h`
-  `Station.cpp`

From a command prompt, execute the following command:

```bash
~profname.proflastname/submit 345_ms1
```

and follow the instructions.

**A successful submission does not guarantee full credit!**



