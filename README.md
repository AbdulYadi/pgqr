# pgqr
PostgreSQL extension to generate QR code

This project adds 2 functionality to QR code generator from repository https://github.com/swex/QR-Image-embedded:<br />
1. In-memory monochrome bitmap construction (1 bit per pixel).<br />
2. Wrap the whole package as PostgreSQL extension.<br />

This project has been compiled successfully in Linux against PostgreSQL version 11.<br />
$ make clean<br />
$ make<br />
$ make install<br />

On successful compilation, install this extension in PostgreSQL environment<br />
$ create extension pgqr<br />

Function has 4 parameters:
1. t text: text to be encoded.<br />
2. correction_level integer: 0 to 3.<br />
3. model_number integer: 0 to 2.<br />
4. scale integer: pixels for each dot.<br />

Let us create a QR Code<br />
$ select pgqr('QR Code with PostgreSQL', 0, 0, 4);<br />
The output is monochrome bitmap ready for display.