const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>UGV01_BASE_WEB</title>
    <meta name="viewport" content="width=device-width,initial-scale=1.0">
    <!-- <script src="http://code.jquery.com/jquery-1.9.1.min.js"></script> -->
    <style type="text/css">
    html {
        display: inline-block;
        text-align: center;
        font-family: sans-serif;
    }
    body {
        background-image: -webkit-linear-gradient(#3F424F, #1E212E);
        font-family: "roboto",helt "sans-serif";
        font-weight: lighter;
        background-position: center 0;
        background-attachment: fixed;
        color: rgba(255, 255, 255, 0.6);
        font-size: 14px;
    }
    .cc-btn {
        border: 0;
        cursor: pointer;
        color: #fff;
        background: rgba(164,169,186,0);
        font-size: 1em;
        width: 100px;
        height: 100px;
         -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none; 
    }
    .cc-middle{
        width: 100px;
        height: 100px;
        border-radius: 50%;
        background-color: rgba(94,98,112,0.8);
    }
    .cc-btn:hover svg, .cc-middle:hover {
        opacity: 0.5;
    }
    .cc-btn:active svg, .cc-middle:hover{
        opacity: 0.5;
    }
    .controlor-c > div{
        width: 300px;
        height: 300px; 
        background-color: rgba(94,98,112,0.2);
        border-radius: 40px;
        box-shadow: 10px 10px 10px rgba(0,0,0,0.05);
        margin: auto;
    }
    .controlor-c > div > div{
        display: flex;
    }
    main {
        width: 960px;
        margin: auto;
    }
    section{margin: 40px 0;}
    .for-move {
        display: flex;
        align-items: center;
    }
    .for-move-a, .for-move-b{
        flex: 1;
        margin: 0 20px;
    }
    .h2-tt {
        font-size: 2em;
        font-weight: normal;
        color: rgba(255, 255, 255, 0.8);
        text-transform: uppercase;
    }
    .info-device-box .info-box{display: flex;}
    .info-device-box .info-box{padding: 20px 0;}
    .num-box-big > div, .num-box-sma > div{flex: 1;}
    .num-box-big > div:first-child{border-right: 1px solid rgba(216,216,216,0.1);}
    .num-box-mid {
        flex-wrap: wrap;
        justify-content: space-between;
    }
    .num-box-mid div{
        width:33.3333%;
        margin: 20px 0;
    }
    .info-device-box .info-box > div > span {
        display: block;
    }
    .info-box {
        background-image: linear-gradient(to right, rgba(94, 98, 112, 0.3), rgba(75, 80, 95, 0.3)) ;
        margin: 20px auto;
        border: 1px solid rgba(216, 216, 216, 0.1);
        box-shadow: 10px 10px 10px rgba(0,0,0,0.05);
        border-radius: 4px;
        color: rgba(255,255,255,0.5);
    }
    .big-num{font-size: 3em;}
    .mid-num{font-size: 2em;}
    .sma-num{font-size: 1.2em;}
    .num-color{
        background-image: linear-gradient(rgba(255,255,255,1),rgba(255,255,255,0.5));
        background-clip: text;
        color:transparent;
        -webkit-background-clip: text;
        -moz-background-clip: text;
        -ms-background-clip: text;
        font-weight: 900;
        line-height: 1em;
        margin: 0.5em 0;
    }
    .num-color-red{
        background-image: linear-gradient(rgba(181,104,108,1),rgba(181,104,108,0.5));
        background-clip: text;
        color:transparent;
        -webkit-background-clip: text;
        -moz-background-clip: text;
        -ms-background-clip: text;
        font-weight: 900;
        line-height: 1em;
        margin: 0.5em 0;
    }
    .controlor > div {margin: 80px 0;}
    .json-cmd-info{
        display: flex;
        flex-wrap: wrap;
    }
    .json-cmd-info > div {
        width: 33.33333%;
        padding: 10px 0;
    }
    .json-cmd-info p{
        line-height: 30px;
        margin: 0;
    }
    .json-cmd-info p span {
        display: block;
        color: rgba(255,255,255,0.8);
    }
    .small-btn{
        color: rgba(255,255,255,0.8);
        background-color: #5E6270;
        border: none;
        height: 48px;
        border-radius: 4px;
    }
    .small-btn-active{
        background-color: rgba(38,152,234,0.1);
        color: #2698EA;
        border: 1px solid #2698EA;
        height: 48px;
        border-radius: 4px;
    }
    .feedb-p input{
        width: 100%;
        height: 46px;
        background-color: rgba(0,0,0,0);
        padding: 0 10px;
        border: 1px solid rgba(194,196,201,0.15);
        border-radius: 4px;
        color: rgba(255, 255, 255, 0.8);
        font-size: 1.2em;
        margin-right: 10px;
    }
    .control-speed > div {
        width: 290px;
        margin: auto;
    }
    .control-speed > div > div{display: flex;}
    .control-speed label {flex: 1;}
    .small-btn, .small-btn-active{
        width: 90px;
    }
    .feedb-p{ display: flex;}
    .fb-input-info{
        margin: 0 20px;
    }
    .fb-info {margin: 20px;}
    .fb-info > span{line-height: 2.4em;}
    .btn-send:hover, .small-btn:hover{background-color: #2698EA;}
    .btn-send:active, .small-btn:active{background-color: #1b87d4;}
    .w-btn{
        color: #2698EA;
        background: transparent;
        padding: 10px;
        border: none;
    }
    .w-btn:hover{color: #2698EA;}
    .w-btn:active{color: #1b87d4;}
    @media screen and (min-width: 768px) and (max-width: 1200px){
        body{font-size: 16px;}
        main {
            width: 100%;
        }
        .for-move {
            display: block;
        }
        /* .controlor-c > div{width: 600px;height: 600px;}
        .cc-btn{width: 200px;height: 200px;} */
        .json-cmd-info{display: block;}
        .json-cmd-info p span{display: inline;}
        .json-cmd-info > div{
            display: flex;
            width: auto;
            padding: 20px;
            flex-wrap: wrap;
            justify-content: space-between;
        }
        .control-speed > div{width: 600px;}
        section{margin: 20px 0;}
    }
    @media screen and (min-width: 360px) and (max-width: 767px){
        main {
            width: 100%;
        }
        .for-move {
            display: block;
        }
        .json-cmd-info{display: block;}
        .json-cmd-info p span{display: inline;}
        .json-cmd-info > div{
            display: flex;
            width: auto;
            padding: 20px;
            flex-wrap: wrap;
            justify-content: space-between;
        }
        section{margin: 10px 0;}
        .info-box{margin: 10px auto;}
        .info-device-box .info-box{padding: 10px;}
        .num-box-mid div{margin: 10px 0;}
        .controlor-c > div{
            width: 270px;
            height: 270px;
        }
        .cc-btn{
            width: 90px;
            height: 90px;;
        }
        .big-num{font-size: 2em;}
        .controlor > div{margin: 40px 0;}
    }
    </style>
</head>
<body>
<main>
  <div class="slider-container">
    <label for="slider">Value: <span id="sliderValue">0</span></label><br>
    <input 
      type="range" 
      id="slider" 
      min="0" 
      max="255" 
      value="0" 
      oninput="updateValue(this.value)"
    >
  </div>
</main>
<script>

    var speed = 0;
    var send_heartbeat = 1;

    setInterval(function() {
        heartBeat();
    }, 1000);

    function updateValue(value) {
        document.getElementById("sliderValue").innerHTML = value;
        speed = value;
    }

    function heartBeat() {
        if (send_heartbeat == 1) {
            var jsonCmd = {
                "T":1,
                "S":speed
            }
            var jsonString = JSON.stringify(jsonCmd);
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "js?json=" + jsonString, true);
            xhr.send();
        }
    }
    function cmdFill(rawInfo, fillInfo) {
        document.getElementById(rawInfo).value = document.getElementById(fillInfo).innerHTML;
    }
    function jsonSend() {
        send_heartbeat = 0;
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
              document.getElementById("fbInfo").innerHTML =
              this.responseText;
            }
        };
        xhttp.open("GET", "js?json="+document.getElementById('jsonData').value, true);
        xhttp.send();
    }
</script>
</body>
</html>
)rawliteral";
