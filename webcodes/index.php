<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>EcoFloat</title>
    <style>
        :root {
            --background: hsl(0, 0%, 100%);
            --foreground: hsl(240, 10%, 3.9%);
            --primary: hsl(240, 5.9%, 10%);
            --primary-foreground: hsl(0, 0%, 98%);
            --secondary: hsl(240, 4.8%, 95.9%);
            --secondary-foreground: hsl(240, 5.9%, 10%);
            --border: hsl(240, 5.9%, 90%);
            --radius: 0.5rem;
        }

        body {
            font-family: 'Inter', sans-serif;
            margin: 0;
            display: flex;
            flex-direction: column;
            min-height: 100vh;
            background-color: var(--background);
            color: var(--foreground);
        }

        header {
            background-color: #4169e1;
            padding: 10px 20px;
            display: flex;
            align-items: center;
        }

        header a {
            color: white;
            text-decoration: none;
            font-size: 1.5rem;
            display: flex;
            align-items: center;
        }

        header svg {
            margin-right: 10px;
        }

        main {
            flex: 1;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            padding: 40px 20px;
            text-align: center;
        }

        h1 {
            color: #4169e1;
            font-size: 2.5rem;
            margin: 0;
        }

        p {
            color: #778899;
            font-size: 1.25rem;
            margin: 10px 0 20px;
        }

        img {
            max-width: 100%;
            border-radius: var(--radius);
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            margin-top: 20px;
        }
    </style>
</head>
<body onload = "table();  ">
    <script type="text/javascript">
        function table(){
            const xhttp = new XMLHttpRequest();
            xhttp.onload = function(){
                document.getElementById("table").innerHTML = this.responseText;   
            }

            xhttp.open("GET", "system.php");
            xhttp.send();
        }

       setInterval(function(){
            table();
       },1);

    </script>
    <header>
        <a href="#">
            <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <path d="M12 22V8"></path>
                <path d="M5 12H2a10 10 0 0 0 20 0h-3"></path>
                <circle cx="12" cy="5" r="3"></circle>
            </svg>
            <span>EcoFloat</span>
        </a>
    </header>
    <main>
        <h1>Welcome to EcoFloat</h1>
        <p>Explore the depths of the ocean with our innovative marine prototype</p>
        <img src="/images/PrototipoVistaSuperior 2.png" alt="EcoFloat" width="800" height="400">
    <br>
    <br>
        <div id="table">

        </div>
    </main>
</body>
</html>
