import { SatelliteModel } from './satellite.mjs'



export class MoonModel extends SatelliteModel {
    constructor(config) {
        super(config.distance, config.orbits);
        this._size = config.size;
        this._color = config.color;
        this._phase = config.phase;
        this._observers = new Array();
    }

    addObserver(observer) {
        this._observers.push(observer);
    }

    _observe() {
        this._observers.forEach((observer) => observer.onMoonModelChange(this));
    }


    get phase() {
        return this._phase
    }

    set phase(value) {
        if (this._phase != value) {
            this._phase = value;
            this._observe();
        }
    }

    get color() {
        return this._color
    }

    set color(value) {
        if (!["white", "silver"].includes(value)) {
            throw Error('invalid value')
        }
        if (this._color != value) {
            this._color = value;
            this._observe();
        }
    }

    get size() {
        return this._size
    }
}

export class MoonController {
    constructor(model) {
        this._model = model;
    }
    get model() {
        return this._model;
    }

    cycle() {
        this._model.phase = (this._model.phase + 1) % 4;
    }

    isNewMoon() {
        return this._model.phase == 0
    }
}

export class MoonView {
    createCanvas() {
        const canvas = document.createElement("canvas");
        canvas.setAttribute("id", this._id + "-canvas");
        canvas.width = 200;
        canvas.height = 200;
        canvas.setAttribute("style", "border: 1px solid black");
        return canvas;
    }

    constructor(model, controller, div, id, config) {
        this._model = model;
        this._controller = controller;
        this._div = div;
        this._id = id;
        this._div.innerHTML = "Moon(id=" + this._id + ", color=" + this._color + ")";
        this._canvas = this.createCanvas();
        this._div.appendChild(this._canvas);
        const me = this;
        this._model.addObserver(this);
        setInterval(() => { me.cycle(); }, 1000);
    }

    onMoonModelChange() {
        this.redraw();
    }

    redraw() {
        const canvas = this._canvas;
        canvas.width = canvas.width;
        const context = this._canvas.getContext("2d");
        const x = canvas.width / 2;
        const y = canvas.height / 2;
        const r = 0.80*Math.min(x,y);
        let sAngle = 0;
        let eAngle = Math.PI*2;
        const counterclockwise = false;

        if (this._phase == 1) {
            eAngle = Math.PI;
        } else if (this._phase == 3) {
            sAngle = Math.PI;
        }

        sAngle += Math.PI/2;
        eAngle += Math.PI/2;

        context.beginPath();
        context.arc(x,y,r,sAngle,eAngle,counterclockwise);
        context.fillStyle=(this._phase == 0) ? "black" : this._color; 
        context.fill();
    }

}

class Moon

export function MoonInstantiate() {
    const divs = document.getElementsByClassName("moon");
    for (let i = 0; i < divs.length; ++i) {
        const div = divs[i];
        const id = "moon-" + i;
        const config = JSON.parse(div.getAttribute("data-config"));
        const moon = new Moon(div, id, config)
    }
}
