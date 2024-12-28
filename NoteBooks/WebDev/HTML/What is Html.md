- Basic building block.
- Skeleton of web-page.
- Description of web-page.
![[html.png]]
### Hyper Text:
- Hypertext is a kind of specially-formatted text that provides a link to other content. Hypertext allows system designers to organize information in a branching structure instead of a linear one. Clicking a hypertext link (called a hyperlink) will send the user to another part of the current document or a separate document entirely. Hypertext links are a fundamental building block of the Internet, allowing users to navigate in a web browser from page to page and from site to site. 
### Markup Language:
- A markup language is one that is designed for defining and presenting text.HTML(Hyper Text Markup Language), is an example of a markup language.
- Within a text file such as an HTML file, elements are _marked up_ using tags which explain the purpose of that part of the content.
- <span style="color:#ff0000;">Tags: in HTML, a tag is used for creating an element.</span>
- <span style="color:#00ff00";>Elements: An element is a part of web-page.in XML and HTML, an element may contain a data item or chunk of text or an image or perhaps nothing.
</span>
### Language:
- set of rules.
> [!NOTE]
> - Html provides description of web-page.
> - CSS: formatting/appearance.
> - Java script:  functionality.

#### Tags:
- is an annotation.
- that tell your browser to render things.
- symbol, that tell your browser to render different things.
- tag is some thing that tells browser to render different things.
### Basic HTML file structure:
 ![[html2.png]]
#### Comments:
- syntax:
- <!--- comment-->

- HTML is not case sensitive.
- HTML doc can be opened in 2 ways.
	1) Text Editor.
	2) Web Browser.

<span style="color:#ff0000;">Every HTML element has a default display value, depending on what type of element it is.</span>
<span style="color:#00ff00;">The two most common values are block and inline.</span>
#### Block element:
- A block-level element always starts on a new line, and the browser automatically add some space (a margin) before and after the element.
- A block-level element always takes up the full width available (stretches out to the left and right as far as it can).
- examples: div , p tag.
#### Inline element:
- An inline element does not start on a new line.
- An inline element element only takes up as much width as necessary.
- example: span tag.


### HTML Components:
- < html > tag: This acts as container for every other elements in document except the < !DOCTYPE html> tag.
- < head > tag: Includes all the document's metadata.
- < title > tag: Defines the title of the document which is displayed in the browser's title bar.
- < body > tag: Acts as a container for the document's content that get displayed on the browser.
```
<!DOCTYPE html> 
<html lang="en">
<head>
<title>My Notes </title>
</head>
<body>...</body>
</html>
```
- < !DOCTYPE html > specifies that we are working with an HTML5 document.
- <span style="color:#00ff00;">The following tags contribute extra information to the HTML document:</span>
- < meta > tag: This tag can be used to define additional information about the web-page.
- < link > tag: Used to link the document to an external resource.
- < style > tag: Used for defining styles for the document.
- < script > tag: Used to write code snippets (usually JavaScript) or to link the document to an external script.
```
<head>
<meta charset="UTF-8" />
<meta http-equiv="X-UA-Compatible" content="IE=edge" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<link rel="stylesheet" href="style.css" />
<title>Code Help HTML Cheat Sheet</title>
<style>
*{
font-size: 40px;
}
</style>
<script>
alert ('message');
</script>
</head>

```

Next page, [[Structure of HTML document]].
