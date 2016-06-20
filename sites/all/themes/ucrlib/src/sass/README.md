# Sass Structure

The Sass folder structure is based upon **components**. A component is the same as:

* "Object" in OOCSS
* "Module" in SMACSS
* "Block" in BEM's Block-Element-Modifier
* "UI Pattern"

Basically, a component is a reusable chunk of css. Components may be self contained, or they may be made up of multiple/smaller sub-components.

Some components may be a single class/element, where other will be constructed of multiple nested classes/elements.

See <http://www.slideshare.net/JohnAlbin/sassconf-managing-complex-projects-with-design-components> for more.

--------------------

## Folders

All folders **only** contain partials.

### /base

This folder contains base styles. Any general styles go here. By default, there is a hacked up version of _normalize.css_, _font_ information, a _print_ partial, and an _init_ partial containing variables, Compass plugins, etc.

The _layout_ config file contains variables relating to @media queries (using the [Breakpoint](http://breakpoint-sass.com/) Compass plugin).

### /components

This folder contains all of the individual components. Each partial contains one and only one component.

See [components](#components) below for details about a component partial.

This folder will get large, possibly very large depending on the size of the site. But by putting all components into a single folder makes it very easy to find components.

* Inspect the DOM
* Find the class on the design component
* Look for a file with that name in the componnts folder

### /layouts

Includes all the layout partials themselves. All layouts should use the SMACSS convention of prefixing with `l-` as in `l-my-layout`. Layouts are built using [Singularity](https://github.com/Team-Sass/Singularity).

--------------------

## [Components](id:components)

As stated above, each component partial contains one and only one component. However, each component may have additional variants, and should be placed into the same partial.

Any mixins and/or silent placeholders directly related to the component should be placed into te same partial.

### Partial naming

The name of the partial should be the same as the name of the component. So if the component's class (in the HTML) is `.my-component`, then the partial should be named `_my-component.scss`.

### Sub-components

Sub-components, or component parts, are smaller pieces of the larger component.

For example, a node teaser would be the component, with the teaser's title, date, and body snippet being the sub-components.

Separate the component's name from the sub-component using two underscores, as in `.my-component__title`, where _title_ is the sub-component.

So, if the name of the component is `my-component`, in the partial should be the following sass/css classes:

* `.my-component`
* `.my-component__title`
* `.my-component__date`
* `.my-component__body`

### Variants

Variants are simply components that are slightly different from their "parent" component.

For example, a button could be the parent component, and several colors of the button would be variants.

Separate the component's name from the variant using two dashes, as in `.my-component--variant1`, where _variant1_ is the name of the variant.

### Sub-components & variants

Sub-components and variants can be combined. If a _title_ field (`.my-component__title`) has a variant, then the variant would be added at the end: `.my-component__title--variant1`.

If, however, the main component has a variant (`.my-component--variant1`) and has a title different from the main component's title, then it would be named like so: `.my-component--variant1__title`.
