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

Function <b>pgqr</b> has 4 parameters:<br />
1. <b>t</b> text: text to be encoded.<br />
2. <b>correction_level</b> integer: 0 to 3.<br />
3. <b>model_number</b> integer: 0 to 2.<br />
4. <b>scale</b> integer: pixels for each dot.<br />

Let us create a QR Code<br />
$ select pgqr('QR Code with PostgreSQL', 0, 0, 4);<br />
The output is a monochrome bitmap ready for display.<br />
<img src="https://abdulyadi.files.wordpress.com/2019/01/image-1.png?w=545">