<span style="color:#00ff00;">There are no examples, if you are using this as note ,try googling thing,and try doing things on your own.</span>

- While constructing your HTML document, you can use certain tags to establish its structure.

#### Heading tags:
- Heading tags are used for specifying headings in your html document.
- `<h1>` to `<h6>` providing different size of headings.
- h1 being largest and h6 being smallest.
#### Paragraph tag:
- you use `<p>` tag to create a paragraph.
- is a block level element.

#### Div tag:
- `<div>` tag is a generic, that can be used as container to house other HTML elements.
- is a block level elements.
- The `<div>` element is often used to group sections of a web page together.
- can be used for anything.
#### Span tag:
- `<span>` tag is similar to `<div>`tag but they are inline elements by nature.

#### Line break:
- `<br/>` tag is used to break the current line and move to next line.

#### Horizontal rule:
- `<hr/>` tag is used to make a horizontal line in html.

#### Images in html:
- In HTML, we use the `<img/>` tag to insert image into the document.
- Here are some attribute of the `<img/>` tag.
- `src`: is used to specify the location of the image on your computer or the internet.
- `alt`: specifies alternate text that displays if the image cannot be rendered. This text is also helpful for screen readers.
- `height`: determines the height of the image.
- `width`: determines the width of the image.
- `border`: specifies the thickness of the borders around the image. If no border is added, it set to 0.



#### Text formatting in HTML:
- HTML provides multiple methods for formatting text. Let's take a brief look at them now:
- The `<i>` tag formats text in italics.
- The `<b>` tag formats text in bold.
- The `<strong>` tag also formats text in bold and is used to emphasize important information.
- The `<em>` tag is another emphasis tag that formats text in italics.
- The `<sub>` tag formats text as subscript, like Carbon Dioxide : CO<sub>2</sub>.
- The `<sup>` tag formats text as a superscript, like the power of a number, 23<sup>2</sup>.
- The `<small>` tag decreases the size of text.
- The `<del>` tag formats text as deleted by striking a line through it.
- The `<address>` tag is used to show the author's contact information.
- The `<abbr>` tag denotes an abbreviation.
- The `<code>` tag formats text as code snippets.
- The `<mark>` tag highlights text.
- The `<ins>` tag formats text as inserted, which is usually underlined.
- The `<blockquote>` tag is used to enclose a section of text quoted from another source.
- The `<q>` tag is used for shorter inline quotes.
- The `<cite>` tag is used to cite the author of a quote.

#### Links in HTML:

- The `<a>` tag, also referred to as the anchor tag, is used to establish hyperlinks that link to other pages (external web pages included) or to a particular section within the same page.
- Here are some attributes of the `<a>` tag:
- `href`: attribute specifies the URL that the link will take the user to when clicked.
- `download`: attribute specifies that the target or resource clicked is downloadable file.
- `target`: attribute specifies where the linked document or resource should be opened. This could be in the same window or a new window.

#### Lists in HTML:
- Lists group similar type of items.
- provides three type of list.
- ordered list , unordered list, description list.
- `<ol>` tag defines an ordered list.
- `<ul>` tag defines an unordered list.
- `<li>` tag is used to create items in the list.(ordered list, unordered list , description list.)
- The **`<dl>`** [HTML](https://developer.mozilla.org/en-US/docs/Web/HTML) element represents a description list. The element encloses a list of groups of terms (specified using the [`<dt>`](https://developer.mozilla.org/en-US/element) and descriptions (provided by [`<dd>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/dd) elements). Common uses for this element are to implement a glossary or to display metadata (a list of key-value pairs).
- Example:
```
<p>Cryptids of Cornwall:</p>

<dl>
  <dt>Beast of Bodmin</dt>
  <dd>A large feline inhabiting Bodmin Moor.</dd>

  <dt>Morgawr</dt>
  <dd>A sea serpent.</dd>

  <dt>Owlman</dt>
  <dd>A giant owl-like creature.</dd>
</dl>
```
- Output:
`Cryptids of Cornwall:`

`Beast of Bodmin`

	`A large feline inhabiting Bodmin Moor.`

`Morgawr`

	A sea serpent.`

`Owlman`

	`A giant owl-like creature.`

#### Forms in HTML:
- The `<form>` element is used to create a form in HTML. Forms are used to gather user input.
- Some attributes associated with the `<form>` element include:
- `action`: attribute specifies where the form data should be sent when the form is submitted.
- `target`: attribute specifies where to display the form's response.
- `autocomplete`: attribute can have a value of on or off and determines whether the browser should automatically fill in the form.
- `novalidate`: attribute specifies that the form should not be validated.
- `method`: attribute specifies the HTTP method to use when sending form data.
- `name`: attribute specifies the name of the form.
- `required`: attribute specifies that an input element cannot be left blank.
- `autofocus`: attribute gives focus to the input elements when the page loads.
- `disabled`: attribute disables an input element, preventing the user from interacting with it.
- `placeholder`: attribute is used to provide a hint to the user about what information is required for the input element.

Other input elements that can be used in forms include:

- `<textarea>`: allows users to enter multiple lines of text as input.
- `<select>`: provides a list of options for users to choose from.
 - `<option>`: creates a single option within a `<select>` element.
- `<input>`: provides an input field for users to enter data.
- `type`: attribute specifies the type of data that can be entered.
- `<button>`: creates a button that can be clicked to perform an action.
```
<form action="/Submit_URL/" method="post">
<label for="FirstName"> First Name: </label>
<input type="text"
name="FirstName"
placeholder="First Name"
required >
<label for="LastName"> Last Name: </label>
<input type="text"
name="LastName"
placeholder="Last Name"
required >
<label for="add"> Address: </label>
<textarea name="add"></textarea>
<label for="age"> Age: </label>
<select id="age">
<option value="11-20">11-20</option>
<option value="21-30">21-30</option>
<option value="31-40">31-40</option>
<option value="41-40">41-50</option>
</select>
<input type="submit" value="Submit">
</form>
```


#### Tables in HTML:
- The `<table>`: tag defines a HTML table.
- `<thead>`: defines the header information for each column in the table.
- `<tbody>`: defines the body or content of the table.
- `<tfoot>`: defines the footer information of the table. 
- `<tr>`:represents a row in the table.
- `<td>`: represents a single cell in the table.
- `<th>`: represents the heading for a column of values in the table.
- Example:
<table>
<thead>
<tr>
<th> Name </th>
<th> CGPA </th>
</tr>
</thead>
<tbody>
<tr>
<td>my_notes1 </td>
<td>9.66 </td>
</tr>
<tr>
<td>my_notes2 </td>
<td>9.72 </td>
</tr>
</tbody>
<tfoot>
<tr>
<td>my_notes3 </td>
<td>10 </td>
</tr>
</tfoot>
</table>

some attributes:
- `colspan`: will increase size of column.
- `rowsapn`: will increase size of row.
>[!Note]
>TODO: Column groups


#### Tags in HTML

- The following tags were introduced in HTML5:
- `<header>` tag: defines the header section of a web-page.
- `<footer>` tag: defines the footer section of a web-page.
- `<main>` tag: defines the main content section of a web-page.
- `<article>` tag: defines a standalone section of content, such as an article.
- `<nav>` tag: used to contain navigation links.
- `<meter>` tag: used to measure data within a given range.
- `<progress>` tag: used as a progress bar to indicate the completion of a task.
- `<dialog>` tag: used to create a dialog box.
- `<audio>`tag: used to embed an audio file on a web-page.
- `<video>` tag: used to embed a video on a web-page.
- `<section>` tag: defines a section within a web-page.
• `<aside>` tag: often used for content placed in a sidebar.
- `<time>` tag: used for formatting dates and times.
- `<figure>` tag: used for figures such as charts.
- `<figcaption>` tag: provides a description for a `<figure>`.


#### Character and Symbols:
- In HTML documents, some symbols may not be directly available on the keyboard. However, there are several ways to include these symbols in a document. These include using the symbol's
  entity name, decimal value, or hexadecimal value.
- Copyright Symbol: `&copy`;
- Dollar Symbol: `&dollar`;
- Ampersand Symbol: `&amp`;
- Greater than Symbol: `&gt`;
- Less than Symbol: `&lt`;

#### Bookmarks:
- move form one point to another point in web page.
- id of destination tag.
- `<a href="#destiantion>go there</a>` this is how you write the bookmark.
- for smooth transition:`html{scroll-behaviour:smooth;}`
#### Call:
- `<a href="tel:8210999282">call</a>`
- `tel:mobilenubmer`is used to make a call to a person, it will ask for your calling to make a call to that person.

#### Mails:
- `<a href="mailto:mey@gmail.com">mail</a>`
- `mailto:mail_address`: is used to send a mail to a given mail_address.

>[!Note]
>title attribute: is used to provide some caption about the content inside the  tags kind of tool tip.

There are so many tags left , but these are like main ones, if you need any other tag, just google it. 

Moving to CSS, [[CSS fundamentals]].
