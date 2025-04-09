#n## Laravel installation
- follow steps on official website for steps
### Creating a new Laravel project
- on terminal
```
laravel new <project_name>
```
- choose desired options
- you can view the create project by
	- `cd project_name`
	- then run `composer run dev`	
### Routes in `Laravel`
- Routes in Laravel defines, how your application responds to different HTTP requests (like GET, POST, PUT ,DELETE).
- They map `URLs` to controller methods or closure functions.
- **GET:**
	- Used to fetch or view data
	- safe for retrieving pages,lists, or specific resources.
	- *Example use Case*: Fetching a list or users or displaying a web page.
- **POST:**
    - Used to send data to the server, usually for creating a new record.
    - Not idempotent (sending multiple requests creates multiple records).
    - *Example Use Case:* Submitting a form to create a user.	
- **PUT**
	- Used to **update an existing resource**.
	- Requires the full updated data for the record.
	- *Example Use Case: Updating a user’s profile information.
- **DELETE:**
	- Used to delete a resource.
    - Cannot be undone (should be used with caution).
    - *Example Use Case*: Deleting a user from the database. 
#### Use Case:
- Routes are used to define endpoints for web pages, APIs, or handling form submissions. For example:

- Displaying a homepage (GET /)
- Submitting a contact form (POST /contact)
- Fetching API data (GET /`api`/users)

#### Where It Lives in Laravel?
- Routes are stored in the **/routes/ folder**. Laravel has different route files for different types of applications:

    - `routes/web.php → Handles web routes (browser-based)`
    - `routes/api.php → Handles API routes`
    - `routes/console.php → Defines Artisan commands`
    - `routes/channels.php → Defines broadcasting channels`

##### Example:

**`Basic route in web.php`:**
```
Route::get('/', function () {
    return view('welcome');
});
```

**Route with a controller:**
```
Route::get('/about', [PageController::class, 'about']);
```

**Route with parameters:**
```
Route::get('/user/{id}', function ($id) {
    return "User ID: " . $id;
});
```

#### How to define a route?
```
// basic route
//go to web.php

Route::get("/about",function(){
return view("about");
});

// this will load a view(file) when the url is /about and method is get, to browser
``` 

```
Route::get("/about",function(){
return "any thing";
});
// you can return mostly anything , like array, some value, variable etc.
// when we return an array(asoc) it will when do get method it will be automatically converted to JSON format when send to browser
```

### Blade in Laravel
- Blade is `Laravel's` built-in `templating` engine that helps you write dynamic HTML pages with PHP logic while keeping the code clean and readable.
#### Use Case:
- Blade is used to create views (web pages) by combining HTML with dynamic content. It allows you to use variables, loops, conditions, and template inheritance.
#### Where It Lives in Laravel?
- Blade files are stored in the resources/views/ folder and have a `.blade.php` extension.
- *Example:*`resources/views/home.blade.php`
Laravel Components
Definition:

Laravel Blade Components are reusable UI blocks that help you keep your Blade templates clean and modular. They allow you to create small, independent pieces of UI that can be reused across multiple views.
Use Case:

    Creating reusable buttons, forms, alerts, cards, modals, etc.
    Reducing duplication in Blade templates.
    Making templates more structured and maintainable.

Where It Lives in Laravel?

    Blade components are stored in resources/views/components/.
    If you create a class-based component, its logic is in app/View/Components/.

**Creating a Blade Component (Without PHP Class)**
- Step 1: Create a Blade Component
	- *Manually create a file:*
	- `resources/views/components/button.blade.php`
- Step 2:Define the Component `UI`
 
```
<button class="bg-blue-500 text-white px-4 py-2 rounded">
    {{ $slot }}
</button>
```

- Step 3: Use the Component in Views
```
<x-button>Click Me</x-button>
```

#### Creating a Class-Based Component
- *Run in terminal:*

```
php artisan make:component Alert
```
- after this look inside `resoureces/views` there should be a `components` folder , edit the file manually.

#### Slot Variable in Blade Components

- A slot in Laravel Blade components is a placeholder for dynamic content inside a component. It allows you to pass custom content to a component while keeping the layout reusable.

**Use Case:**
- Slots are used when you need to pass content inside a Blade component, Example:
- *Example:*
##### Default Slot (Basic Usage)
		- A default slot is used when you pass content inside a component.
	- Step 1: Create the Blade Component

`resources/views/components/button.blade.php`

```
<button class="bg-blue-500 text-white px-4 py-2 rounded">
    {{ $slot }}  <!-- This will be replaced with the passed content -->
</button>
```

- Step 2: Use the Component in a View

```
<x-button>Click Me</x-button>
```

##### Named Slots (Multiple Slots in a Component)

- Named slots allow passing multiple pieces of content into different sections of a component.
 
- Step 1: Create a Component for a Card

`resources/views/components/card.blade.php`

```
<div class="border p-4 rounded shadow">
    <h2 class="text-lg font-bold">{{ $title }}</h2>
    <div>
        {{ $slot }} <!-- Main content slot -->
    </div>
    <div class="text-right text-sm text-gray-500">
        {{ $footer }} <!-- Named slot for footer -->
    </div>
</div>
```

- Step 2: Use the Component with Named Slots
```
<x-card>
    <x-slot name="title">My Card Title</x-slot:title>
    This is the main content of the card.
    <x-slot name="footer">Footer Content Here</x-slot:footer>
	</x-card>
```

>[!NOTE]
>**Blade directive**
> {{$variable_name}} translates to `<?php echo $variable_name; ?>`

# Laravel Blade Attribute Object

- The **`$attributes` object** in Laravel Blade Components allows passing dynamic HTML attributes to a component, making them flexible and `customizable`.
**Default Component Attributes**

- **Example: Button Component**  
`resources/views/components/button.blade.php`

```blade
<button {{ $attributes->merge(['class' => 'px-4 py-2 bg-blue-500 text-white rounded']) }}>
    {{ $slot }}
</button>
```

**Using the Component**
```blade
<x-button class="bg-red-500">Click Me</x-button>
```

**Output in HTML:**
```html
<button class="px-4 py-2 bg-red-500 text-white rounded">
    Click Me
</button>
```


 **Passing Additional HTML Attributes**
- The `$attributes` object automatically includes any extra attributes passed to the component.

**Example:**  
```blade
<x-button id="my-button" data-toggle="modal">Click Me</x-button>
```

 **Output in HTML:**
```html
<button id="my-button" data-toggle="modal" class="px-4 py-2 bg-blue-500 text-white rounded">
    Click Me
</button>
```

 **Applying Conditional Attributes**
- You can use **`$attributes->has()`** to check if an attribute exists.

**Example: Add `disabled` If Present**
```blade
<button {{ $attributes->merge(['class' => 'px-4 py-2 bg-blue-500 text-white rounded']) }}
    @if($attributes->has('disabled')) class="opacity-50 cursor-not-allowed" @endif>
    {{ $slot }}
</button>
```

**Using the Component**

```blade
<x-button disabled>Disabled Button</x-button>
```

**Output in HTML:**
```html
<button disabled class="px-4 py-2 bg-blue-500 text-white rounded opacity-50 cursor-not-allowed">
    Disabled Button
</button>
```

## Summary of Blade Attribute Object (`$attributes`)

| Feature                              | Explanation                                                  |
| ------------------------------------ | ------------------------------------------------------------ |
| `{{ $attributes }}`                  | Prints all attributes dynamically.                           |
| `$attributes->merge([...])`          | Merges attributes while ensuring defaults can be overridden. |
| `$attributes->has('name')`           | Checks if a specific attribute exists.                       |
| `$attributes->only(['class', 'id'])` | Extracts only the specified attributes.                      |
| `$attributes->except(['class'])`     | Removes the specified attributes.                            |
`Laravel's` **Blade Attribute Object** makes components dynamic and adaptable, enabling easy customization while maintaining code `reusability`.

# Laravel Blade Component Props

- Props in Laravel Blade components allow passing data from a parent view to a component. They help make components reusable and dynamic by injecting values directly into them.
- kind of like custom named attribute HTML attributes. 
#### Defining Props in a Component
Props are defined using **`@props`** or class-based public properties.

**Example: Alert Component**  
`resources/views/components/alert.blade.php`
```blade
@props(['type' => 'info'])

<div class="p-4 border rounded-lg {{ $type === 'error' ? 'bg-red-500 text-white' : 'bg-blue-500 text-white' }}">
    {{ $slot }}
</div>
```

### **Using the Component**
```blade
<x-alert type="error">Something went wrong!</x-alert>
<x-alert>Everything is fine!</x-alert>
```

**Output in HTML:**
```html
<div class="p-4 border rounded-lg bg-red-500 text-white">
    Something went wrong!
</div>

<div class="p-4 border rounded-lg bg-blue-500 text-white">
    Everything is fine!
</div>
```

#### Using Props in Class-Based Components
Instead of `@props`, you can define props in class-based components.

### **Component Class**  
`app/View/Components/Alert.php`
```php
namespace App\View\Components;

use Illuminate\View\Component;

class Alert extends Component
{
    public string $type;

    public function __construct(string $type = 'info')
    {
        $this->type = $type;
    }

    public function render()
    {
        return view('components.alert');
    }
}
```

**Component View**  
`resources/views/components/alert.blade.php`
```blade
<div class="p-4 border rounded-lg {{ $type === 'error' ? 'bg-red-500 text-white' : 'bg-blue-500 text-white' }}">
    {{ $slot }}
</div>
```

**Using the Component**
```blade
<x-alert type="error">An error occurred!</x-alert>
```

**This achieves the same behavior but allows logic in PHP classes.**

**Passing Multiple Props**

- You can pass multiple props when using a component.

 **Example: Button Component**
```blade
<x-button size="lg" color="red">Click Me</x-button>
```

**Defining Props in Blade Component**
```blade
@props(['size' => 'md', 'color' => 'blue'])
<button class="px-4 py-2 {{ $size === 'lg' ? 'text-lg' : 'text-sm' }} bg-{{ $color }}-500 text-white">
    {{ $slot }}
</button>
```

**This allows setting size and color dynamically.**
#### **Summary of Blade Props**
| Feature | Explanation |
|---------|------------|
| `@props(['name' => 'default'])` | Defines a prop with a default value. |
| `{{ $propName }}` | Accesses a prop value. |
| `public $propName` | Defines props in a class-based component. |
| `new ComponentName($propValue)` | Passes props in a class constructor. |

Laravel Blade props make it easy to pass and manage dynamic data, making components more reusable and maintainable.


# Laravel `request()` Helper Method

- The `request()` helper in Laravel is a global function that retrieves the current HTTP request instance, allowing access to request data, headers, query parameters, and more.

---

## **1. Accessing Request Data**
| Use Case | Example |
|----------|---------|
| **Get all input data** | `request()->all();` |
| **Get a specific input field** | `request('email');` |
| **Get input with a default value** | `request('age', 18);` |
| **Check if input exists** | `request()->has('username');` |
| **Get query parameters** | `request()->query('page');` |

---

## **2. Checking Request Method**
```php
if (request()->isMethod('post')) {
    return "This is a POST request";
}
```

---

## **3. Checking Request URL & Path**
You can retrieve and check the request URL and path.

```php
$url = request()->url(); // Full URL
$path = request()->path(); // Path only

if (request()->is('admin/*')) {
    return "Admin Panel Accessed";
}
```
✅ **`request()->is('admin/*')`** checks if the current request matches a specific pattern.

---

## **4. Getting Headers**
Access HTTP headers using the `request()` helper.

```php
$userAgent = request()->header('User-Agent');
```

---

## **5. Working with Files (File Uploads)**
Use `request()->file()` to handle file uploads.

```php
if (request()->hasFile('avatar')) {
    $file = request()->file('avatar');
    $file->store('avatars'); // Store in storage/app/avatars
}
```

---

## **6. Example Usage in a Controller**
```php
namespace App\Http\Controllers;

use Illuminate\Http\Request;

class UserController extends Controller
{
    public function store()
    {
        $name = request('name');
        return "User name: " . $name;
    }
}
```

---

## **7. Summary**
| Feature | Example |
|---------|---------|
| **Get all request data** | `request()->all();` |
| **Get a specific input** | `request('email');` |
| **Check request method** | `request()->isMethod('post');` |
| **Check request pattern** | `request()->is('admin/*');` |
| **Get request URL** | `request()->url();` |
| **Get request headers** | `request()->header('User-Agent');` |
| **Handle file uploads** | `request()->file('avatar');` |

The `request()` helper simplifies access to request data in Laravel applications!

### **Laravel Wildcards**  

- Wildcards in Laravel allow you to match dynamic values in routes, middleware, request checks, and query patterns.  

## **1. Wildcards in Routes**
Laravel allows dynamic route parameters using curly braces `{}`.

#### **Example: Basic Wildcard**
```php
Route::get('/user/{id}', function ($id) {
    return "User ID: " . $id;
});
```
**Matches:** `/user/1`, `/user/42`, etc.
## **2. Optional Wildcards**
Use `?` for optional parameters and provide a default value.

```php
Route::get('/profile/{name?}', function ($name = 'Guest') {
    return "Hello, " . $name;
});
```
 **Matches:** `/profile/john` → "Hello, john"  
 **Matches:** `/profile/` → "Hello, Guest"

## **3. Regular Expressions in Wildcards**
You can restrict wildcard formats using `where()`.

```php
Route::get('/post/{id}', function ($id) {
    return "Post ID: " . $id;
})->where('id', '[0-9]+');
```
 **Matches:** `/post/123` ✅  
 **Does NOT Match:** `/post/abc` ❌  

---

## **4. Wildcards in `Middleware`**
You can apply `middleware` dynamically to routes using wildcards.

```php
Route::middleware(['auth'])->group(function () {
    Route::get('/dashboard/{section}', function ($section) {
        return "Dashboard Section: " . $section;
    });
});
```
**Applies `middleware` to:** `/dashboard/settings`, `/dashboard/reports`, etc.

---

## **5. Wildcards in `request()->is()`**
The `request()->is()` method supports pattern matching with wildcards (`*`).

```php
if (request()->is('admin/*')) {
    return "You are in the admin panel";
}
```
**Matches:** `/admin/users`, `/admin/settings`   
**Does NOT Match:** `/user/profile`  


## **6. Wildcards in Policies & Gates**
Use wildcards to define authorization rules.

```php
Gate::define('view-report', function ($user, $report) {
    return $user->role === 'admin' || $report->user_id === $user->id;
});
```
 **Allows access if:** User is admin or owns the report.

## **7. Summary Table**
| Feature                      | Example                                | Matches                            |
| ---------------------------- | -------------------------------------- | ---------------------------------- |
| **Basic Wildcard in Routes** | `/user/{id}`                           | `/user/42`                         |
| **Optional Parameter**       | `/profile/{name?}`                     | `/profile/John` or `/profile/`     |
| **Regex Constraints**        | `/post/{id}` + `where('id', '[0-9]+')` | `/post/123` ✅ `/post/abc` ❌        |
| **Middleware Wildcard**      | `/dashboard/{section}`                 | `/dashboard/settings`              |
| **Request Pattern Matching** | `request()->is('admin/*')`             | `/admin/users` ✅ `/user/profile` ❌ |
Laravel wildcards make routing and request handling dynamic and flexible! 




### **Laravel Models in MVC Architecture**

- A **model** in Laravel follows the Model-View-Controller (MVC) architecture. It is responsible for handling data and business logic, representing a database table using Laravel's Eloquent ORM (Object-Relational Mapping).

---

## **1. MVC Role of Models**
📌 **Model (M)**: Manages the database and logic for handling data.
📌 **View (V)**: Displays the data to the user (Blade templates).
📌 **Controller (C)**: Handles user requests and interacts with models to process data before passing it to views.

**Example Workflow:**
1. The user visits a page (`GET /posts`).
2. The **controller** fetches data from the **model**.
3. The **view** displays the data.

---

## **2. Creating a Model**
You can create a new model using Artisan:
```sh
php artisan make:model Post
```
This creates `app/Models/Post.php`.

To generate a model with a migration:
```sh
php artisan make:model Post -m
```

---

## **3. Model Structure**
Example of a simple `Post` model:
```php
namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Post extends Model
{
    use HasFactory;
    
    protected $fillable = ['title', 'content']; // Mass assignable fields
}
```

---

## **4. Model Location**
**Default Location**: `app/Models/`

If the `Models` directory does not exist, Laravel assumes models are stored in `app/`.

---

## **5. Querying the Database**
Eloquent allows easy database queries:

### **Fetching Data**
```php
$posts = Post::all();
$post = Post::find(1);
$posts = Post::where('title', 'Laravel')->get();
```

### **Inserting Data**
```php
Post::create([
    'title' => 'New Post',
    'content' => 'This is a new blog post.'
]);
```

### **Updating Data**
```php
$post = Post::find(1);
$post->title = 'Updated Title';
$post->save();
```

### **Deleting Data**
```php
$post = Post::find(1);
$post->delete();
```
Or directly:
```php
Post::destroy(1);
```

---

## **6. Model Relationships**
Eloquent makes handling relationships easy.

### **One-to-Many**
```php
class User extends Model {
    public function posts() {
        return $this->hasMany(Post::class);
    }
}
```
Usage:
```php
$user = User::find(1);
$posts = $user->posts; // Get all posts by the user
```

### **Many-to-Many**
```php
class Post extends Model {
    public function tags() {
        return $this->belongsToMany(Tag::class);
    }
}
```

---

## **7. Mass Assignment Protection**
Use `$fillable` or `$guarded` to prevent unwanted mass assignment.
```php
protected $fillable = ['title', 'content'];
// OR
protected $guarded = ['id'];
```

---

## **8. Summary Table**
| Feature           | Description                                   |
| ----------------- | --------------------------------------------- |
| **Create Model**  | `php artisan make:model ModelName -m`         |
| **Query Records** | `Model::where('column', 'value')->get();`     |
| **Insert Data**   | `Model::create([...]);`                       |
| **Update Data**   | `$model->update([...]);`                      |
| **Delete Record** | `$model->delete();` or `Model::destroy(id);`  |
| **Relationships** | `hasMany()`, `belongsTo()`, `belongsToMany()` |
 **Models in MVC help separate concerns by keeping business logic in the model, making Laravel applications cleaner and more maintainable! **