# <u>PGQR</u>
PostgreSQL extension to generate QR code

## Overview

This project adds 2 functionality to QR code generator from repository https://github.com/swex/QR-Image-embedded:<br />
1. In-memory monochrome bitmap construction (1 bit per pixel).<br />
2. Wrap the whole package as PostgreSQL extension.<br />

## Installation

This project has been compiled successfully in Linux against PostgreSQL version 11. Type in a terminal these commands to build the extension :
> \$ make clean
> \$ make
> \$ make install<br />

On successful compilation, install this extension in PostgreSQL environment :
> create extension pgqr<br />

## Functionalities

The <b>pgqr</b> function necessarily takes 4 variables as parameters :
1. <b>t</b> of type <i>text</i> : the string to encode ;
2. <b>correction_level</b> of type <i>integer</i> : value from 0 to 3 ;
3. <b>model_number</b> of type <i>integer</i> : values from 0 to 2 ;
4. <b>scale</b> of type <i>integer</i> : number of pixels for each dot (the bigger this number will be the bigger the QR code picture will be, even for a very small string to encode. Recommended value: 4. Adapt to your own preferences).

## Exemple

Let us create a QR Code with the SQL command :
> select pgqr('QR Code with PostgreSQL', 0, 0, 4);

<br />

The output will be some binary data. In order to be able to display it correctly as a bitmap QR code picture you have to insert these binary data inside the <b>\<img></b> HTML tag just like this :
> \<img src="data:image/png;base64,<b>xxxxx</b>" alt="QR Code" />

Replace <b>xxxxx</b> with your binary data par vos données binaires, which preferably, will be received from PostgreSQL as a variable (for example, a variable inside a JSON from a PostgREST API). This works really fine using React on Front end to fetch these data.

Then you should get this result :

<img src="https://abdulyadi.files.wordpress.com/2019/01/image-1.png?w=545">

## Notes

It seems, as discussed at this <a href="https://github.com/AbdulYadi/pgqr/issues/1"><i>issue</i></a> that this extension doesn't handle (yet) the encoding of Cyrillic characters (and maybe even some other charsets). Source of the issue to confirm yet.