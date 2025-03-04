## What is `opengl`?

- `opengl` is mainly considered an `api` that provides us with a large set of functions that we can use to manipulate graphics and images.
- However,`opengl` by itself is not an `api`, but merely a specification,developed and maintained by the `khronos` group.
- The `OpenGL` specification specifies exactly what the result/output of each function should be and how it should perform. It is then up to the developers implementing this specification to come up with a solution of how this function should operate. Since the `OpenGL` specification does not give us implementation details, the actual developed versions of `OpenGL` are allowed to have different implementations, as long as their results comply with the specification (and are thus the same to the user).

- The people developing the actual `OpenGL` libraries are usually the graphics card manufacturers. Each graphics card that you buy supports specific versions of `OpenGL` which are the versions of `OpenGL` developed specifically for that card (series). When using an Apple system the `OpenGL` library is maintained by Apple themselves and under Linux there exists a combination of graphic suppliers' versions and hobbyists' adaptations of these libraries. This also means that whenever `OpenGL` is showing weird behavior that it shouldn't, this is most likely the fault of the graphics cards manufacturers (or whoever developed/maintained the library).  
## Immediate mode (fixed-function pipeline)

- **Overview**
	- Immediate mode(used in `opengl 1.x and 2.x`) is and older method of sending geometry data to the GPU.
	- It uses function like `glBegin()` and `glEnd()` to specify vertices one by one.
	- The pipeline is mostly fixed-function, meaning transformation , lighting , and shading are handled internally by `opengl`.

- **Key Characteristics**
	- ✅  Easy to learn (good for quick prototyping).
	- ❌ Inefficient (each call sends data to the GPU separately).
	- ❌ State-dependent (uses `OpenGL's` internal transformation and lighting states).
	- ❌ No custom `shaders` (fixed-function pipeline handles lighting, colors, etc.).
	- ❌ Deprecated (not available in `OpenGL` Core Profile 3.2+).
	 
- **Performance Issues**
    - CPU Bottleneck: Each function call incurs overhead.
    - No Vertex Buffers: Vertices are sent to the GPU one at a time instead of storing them in a buffer.
    - Redundant Calls: `OpenGL` repeatedly processes the same vertices for each frame.

## Core Profile (modern `Opengl`)

- **Overview**
	- Introduced in `opengl 3.2+`, Core profile removes all deprecated features, including immediate mode.
	- use Vertex buffer object (`VBO`) and vertex array objects(`VAOs`) for storing vertex data efficiently.
	- requires a `shader-based pipeline` with `GLSL`
	- Provides much better performance by leveraging `GPU` memory.
	
- **Key Characteristics**
	- ✅ Highly efficient (data stored in GPU memory).
	- ✅ Uses `VAOs & VBOs` (reduces CPU-GPU communication overhead).
	- ✅ `Customizable` with `shaders` (Vertex & Fragment `Shaders`).
	- ✅ Supports advanced features (instancing, compute `shaders`, etc.).
	- ❌ More complex setup (requires buffers and `shaders`).
	- ❌ Not backward-compatible with immediate mode.

## Core-profile vs Immediate mode

- In the old days, using `OpenGL` meant developing in immediate mode (often referred to as the fixed function pipeline) which was an easy-to-use method for drawing graphics. Most of the functionality of `OpenGL` was hidden inside the library and developers did not have much control over how `OpenGL` does its calculations. Developers eventually got hungry for more flexibility and over time the specifications became more flexible as a result; developers gained more control over their graphics. The immediate mode is really easy to use and understand, but it is also extremely inefficient. For that reason the specification started to deprecate immediate mode functionality from version 3.2 `onwards` and started motivating developers to develop in `OpenGL's` core-profile mode, which is a division of `OpenGL's` specification that removed all old deprecated functionality.

- When using `OpenGL's` core-profile, `OpenGL` forces us to use modern practices. Whenever we try to use one of `OpenGL's` deprecated functions, `OpenGL` raises an error and stops drawing. The advantage of learning the modern approach is that it is very flexible and efficient. However, it's also more difficult to learn. The immediate mode abstracted quite a lot from the actual operations `OpenGL` performed and while it was easy to learn, it was hard to grasp how `OpenGL` actually operates. The modern approach requires the developer to truly understand `OpenGL` and graphics programming and while it is a bit difficult, it allows for much more flexibility, more efficiency and most importantly: a much better understanding of graphics programming.

- This is also the reason why this book is geared at core-profile `OpenGL` version 3.3. Although it is more difficult, it is greatly worth the effort.

- As of today, higher versions of `OpenGL` are available to choose from (at the time of writing 4.6) at which you may ask: why do I want to learn `OpenGL` 3.3 when `OpenGL` 4.6 is out? The answer to that question is relatively simple. All future versions of `OpenGL` starting from 3.3 add extra useful features to `OpenGL` without changing `OpenGL's` core mechanics; the newer versions just introduce slightly more efficient or more useful ways to accomplish the same tasks. The result is that all concepts and techniques remain the same over the modern `OpenGL` versions so it is perfectly valid to learn `OpenGL` 3.3. Whenever you're ready and/or more experienced you can easily use specific functionality from more recent `OpenGL` versions. 


## Extensions

- A great feature of `OpenGL` is its support of extensions. Whenever a graphics company comes up with a new technique or a new large optimization for rendering this is often found in an extension implemented in the drivers. If the hardware an application runs on supports such an extension the developer can use the functionality provided by the extension for more advanced or efficient graphics. This way, a graphics developer can still use these new rendering techniques without having to wait for `OpenGL` to include the functionality in its future versions, simply by checking if the extension is supported by the graphics card. Often, when an extension is popular or very useful it eventually becomes part of future `OpenGL` versions.

- The developer has to query whether any of these extensions are available before using them (or use an `OpenGL` extension library). This allows the developer to do things better or more efficient, based on whether an extension is available: 
```
	if(GL_ARB_extension_name){
	 // Do cool new and modern stuff supported by hardware	
	}
	else{
	// Extesnion not supported: do it the old way	
	}	
```

## State machine

- `OpenGL` is by itself a large state machine: a collection of variables that define how `OpenGL` should currently operate. The state of `OpenGL` is commonly referred to as the `OpenGL` context. When using `OpenGL`, we often change its state by setting some options, manipulating some buffers and then render using the current context.

- Whenever we tell `OpenGL` that we now want to draw lines instead of triangles for example, we change the state of `OpenGL` by changing some context variable that sets how `OpenGL` should draw. As soon as we change the context by telling `OpenGL` it should draw lines, the next drawing commands will now draw lines instead of triangles.

- When working in `OpenGL` we will come across several state-changing functions that change the context and several state-using functions that perform some operations based on the current state of `OpenGL`. As long as you keep in mind that `OpenGL` is basically one large state machine, most of its functionality will make more sense.

Objects

- The `OpenGL` libraries are written in C and allows for many derivations in other languages, but in its core it remains a C-library. Since many of C's language-constructs do not translate that well to other higher-level languages, `OpenGL` was developed with several abstractions in mind. One of those abstractions are objects in `OpenGL`.

- An object in `OpenGL` is a collection of options that represents a subset of `OpenGL's` state. For example, we could have an object that represents the settings of the drawing window; we could then set its size, how many colors it supports and so on. One could visualize an object as a C-like struct:

```
struct object_name {
    float  option1;
    int    option2;
    char[] name;
};
```

- Whenever we want to use objects it generally looks something like this (with `OpenGL's` context visualized as a large struct):

```
// The State of OpenGL
struct OpenGL_Context {
  	...
  	object_name* object_Window_Target;
  	...  	
};
```

```
// create object
unsigned int objectId = 0;
glGenObject(1, &objectId);
// bind/assign object to context
glBindObject(GL_WINDOW_TARGET, objectId);
// set options of object currently bound to GL_WINDOW_TARGET
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_WIDTH,  800);
glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_HEIGHT, 600);
// set context target back to default
glBindObject(GL_WINDOW_TARGET, 0);
```

- This little piece of code is a workflow you'll frequently see when working with `OpenGL`. We first create an object and store a reference to it as an id (the real object's data is stored behind the scenes). Then we bind the object (using its id) to the target location of the context (the location of the example window object target is defined as `GL_WINDOW_TARGET`). Next we set the window options and finally we unbind the object by setting the current object id of the window target to 0. The options we set are stored in the object referenced by `objectId` and restored as soon as we bind the object back to `GL_WINDOW_TARGET`.

- The code samples provided so far are only approximations of how `OpenGL` operates; throughout the book you will come across enough actual examples.

- The great thing about using these objects is that we can define more than one object in our application, set their options and whenever we start an operation that uses `OpenGL's` state, we bind the object with our preferred settings. There are objects for example that act as container objects for `3D` model data (a house or a character) and whenever we want to draw one of them, we bind the object containing the model data that we want to draw (we first created and set options for these objects). Having several objects allows us to specify many models and whenever we want to draw a specific model, we simply bind the corresponding object before drawing without setting all their options again.