- CSS is the language we use to style an HTML document.
- CSS describes how HTML elements should be displayed.
- CSS file contains properties.
#### How to link CSS file to an HTML file:
<h6><span style="color:#00ff00;">There are three ways of inserting a style sheet:</span></h6>
- External CSS
- Internal CSS
- Inline CSS
##### External CSS:
- With an external style sheet, you can change the look of an entire website by changing just one file.
- `<link>` tag is used to link this external CSS file.
- `<link rel="stylesheet" href="path/to/css/file">` 
- `rel`: attribute defines the relation between the files , what kind of file is the one we are trying to link. 
- `href`: is used to specify the file path.
#### Internal CSS:
- An internal style sheet may be used if one single HTML page has a unique style.
- The internal style is defined inside the `<style>` tag, inside the head section.
- `<style> css properties comes here </style>`

#### Inline CSS:
- An inline style may be used to apply a unique style for a single element.
- To use inline styles, add the style attribute to the relevant element. The style attribute can contain any CSS property.
- `<p style="color:red;">This is a paragraph.</p>`

#### How to write CSS file:

##### Selector in CSS:
- is a way using which we can select an element/elements. 
![[Css1.png]]
<span style="color:#00ff00;">Types of selectors:</span>
##### Simple selector:
- select elements based on name, id, class.
###### 1) Element selector,Type selector,Tag selector:
- syntax:
```
tag_name{
property:value;
}

Example:

p{
backgroun-color:#ff0000;
}
```
###### 2) Class selector:
- used in case when we have to apply some kind of style to groups of elements.
- but it can be used for individuals as well.
- but good practice is to used where we have to apply some property to group of elements.
- access element by class `.class_name{property:value;}`
- class_name is not unique in nature.
- `.`: is used to  access element via class.
###### 3) Id selector:
- used in case when we want to apply change to a particular element.
- access element by id `#id_name{property:value:}`
- `#` is used to access element via id.



#### Combinators:
- Using CSS combinators, we can combine selectors to select DOM nodes based on their relationship to other elements within the document node tree. This combining of selectors with combinators creates [complex selectors](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_selectors/Selector_structure#complex_selector).
##### <span style="color:#00ff00;">Types of combinators:</span>
##### [Descendant combinator](https://developer.mozilla.org/en-US/docs/Web/CSS/Descendant_combinator):
- Denoted with one or more spaces, selects nodes that are descendants of the first element. For example, `div span` will match all [`<span>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/span) elements that are inside a [`<div>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/div) element.
###### [Child combinator](https://developer.mozilla.org/en-US/docs/Web/CSS/Child_combinator):
- Is more specific than the descendant combinator. Denoted with the greater than character (`>`), the child combinator selects nodes that are direct children of the first element. Comparing with our previous example, `div > span` will match only the [`<span>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/span) elements that are direct children of a [`<div>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/div) element.

<span style="color:#00ff00;"> CSS also enables selecting elements based on their siblings.</span>

##### [Subsequent-sibling combinator](https://developer.mozilla.org/en-US/docs/Web/CSS/Subsequent-sibling_combinator)
- Denoted with a tilde (`~`), selects siblings. Given `A ~ B`, all elements matching `B` will be selected if they are preceded by `A`, provided both `A` and `B` share the same parent. For example, `h2 ~ p` will match all [`<p>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/p) elements that follow an [h2](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/Heading_Elements), immediately or not.


 ###### [Next-sibling combinator](https://developer.mozilla.org/en-US/docs/Web/CSS/Next-sibling_combinator):
 - Denoted by the plus symbol (`+`), is similar to the subsequent-sibling. However, given `A + B`, it only matches `B` if `B` is immediately preceded by `A`, with both sharing the same parent. Amending our previous example, `h2 + p` will match only the single `<p>` element that _immediately_ follows an `<h2>` element.

###### [Column combinator](https://developer.mozilla.org/en-US/docs/Web/CSS/Column_combinator):
- Denoted by two pipe characters (`||`), which, when supported, selects nodes that belong to a column. For example, `col || td` will match all [`<td>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/td) elements that belong to the scope of the [`<col>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/col).


###### [Namespace separator](https://developer.mozilla.org/en-US/docs/Web/CSS/Namespace_separator) :
- Is another combinator that is generally used in conjunction with the [`@namespace`](https://developer.mozilla.org/en-US/docs/Web/CSS/@namespace) at-rule. This combinator is denoted by a single pipe character (`|`). It enables limiting [type selectors](https://developer.mozilla.org/en-US/docs/Web/CSS/Type_selectors) and the [universal selector](https://developer.mozilla.org/en-US/docs/Web/CSS/Universal_selectors) to a specific namespace. For example, by defining a namespace such as `@namespace SVG url('http://www.w3.org/2000/svg');`, you can include selectors that target elements nested in an SVG namespace only. Declaring `SVG|a` would match links within SVGs and not those in the rest of the document. Namespacing can be useful to target MathML, SVG, or other XML-based content within your HTML.
##### Pseudo-class Selector:
- is a keyword, that represents a special state of element.
- special state.
> [!TODO]
> complete selectors.



##### Specificity:
- The priority of selectors.
- inline CSS > id > class > tag.