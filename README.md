
<h1 align="center">Philosophers</h1>

<h2>Description</h2>
<p><strong>Philosophers</strong> is a project from the 42 cursus that involves solving the classic "Dining Philosophers" problem. The main objective is to understand concurrency, process synchronization, and the challenges of deadlock and starvation in concurrent programming. The project requires implementing a simulation of philosophers dining together, sharing forks, and avoiding conflicts.</p>
<img src"https://github.com/PaLucena/Philosophers/blob/main/img/philo.png">

<h2>Table of Contents</h2>
<ul>
	<li><a href="#requirements">Requirements</a></li>
	<li><a href="#installation">Installation</a></li>
	<li><a href="#usage">Usage</a></li>
	<li><a href="#features">Features</a></li>
	<li><a href="#project-structure">Project Structure</a></li>
	<li><a href="#license">License</a></li>
</ul>

<h2 id="requirements">Requirements</h2>
<p>To compile and run the project, you will need:</p>
<ul>
	<li>A Unix operating system (Linux or macOS).</li>
	<li>gcc or any C compiler.</li>
	<li>Make.</li>
</ul>

<h2 id="installation">Installation</h2>
<p>Clone the project repository and navigate to the main directory:</p>
<pre><code>git clone https://github.com/PaLucena/Philosophers.git
cd Philosophers</code></pre>
<p>Compile the project using the included Makefile:</p>
<pre><code>make</code></pre>
<p>This will generate the <code>philosophers</code> executable in the current directory.</p>

<h2 id="usage">Usage</h2>
<p>To start the philosophers simulation, run the following command:</p>
<pre><code>./philosophers &lt;number_of_philosophers&gt; &lt;time_to_die&gt; &lt;time_to_eat&gt; &lt;time_to_sleep&gt; [&lt;number_of_times_each_philosopher_must_eat&gt;]</code></pre>
<ul>
	<li><code>&lt;number_of_philosophers&gt;</code>: The number of philosophers and forks.</li>
	<li><code>&lt;time_to_die&gt;</code>: Time in milliseconds a philosopher can go without eating before dying.</li>
	<li><code>&lt;time_to_eat&gt;</code>: Time in milliseconds it takes for a philosopher to eat.</li>
	<li><code>&lt;time_to_sleep&gt;</code>: Time in milliseconds a philosopher spends sleeping.</li>
	<li><code>&lt;number_of_times_each_philosopher_must_eat&gt;</code> (optional): Number of times each philosopher must eat before the simulation ends. If not specified, the simulation runs indefinitely.</li>
</ul>
<p>Example:</p>
<pre><code>./philosophers 5 800 200 200</code></pre>

<h2 id="features">Features</h2>
<p>The Philosophers project supports various features to simulate the dining philosophers problem:</p>
<ul>
	<li>Accurate time tracking for philosopher actions.</li>
	<li>Thread management for concurrency.</li>
	<li>Mutexes to avoid race conditions and ensure synchronization.</li>
	<li>Optional parameter to limit the number of meals for each philosopher.</li>
</ul>

<h2 id="project-structure">Project Structure</h2>
<p>The project is organized into the following files and directories:</p>
<ul>
	<li><code>src/</code>: Contains the source code of the simulation.</li>
	<li><code>include/</code>: Contains the header files.</li>
	<li><code>Makefile</code>: Build script to generate the executable.</li>
	<li><code>README.md</code>: Project documentation.</li>
</ul>

<h2 id="license">License</h2>
    <p>This project is licensed under the MIT License. See the <code>LICENSE</code> file for more details.</p>
    
