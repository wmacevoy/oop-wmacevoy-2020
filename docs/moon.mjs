export class Moon {
	createCanvas() {
	  const canvas=document.createElement("canvas");
	  canvas.setAttribute("id",this._id + "-canvas");
	  canvas.width=200;
	  canvas.height=200;
	  canvas.setAttribute("style","border: 1px solid black");
	  return canvas;
	}

    constructor(div, id, config) {
	   this._div = div;
	   this._id = id;
	   this._size = config.size;
	   this._color = config.color;
	   this._phase = config.phase;
       this._div.innerHTML = "Moon(id=" + id + ", color="  + color + ")";
	   this._canvas = this.createCanvas();
	   this._div.appendChild(this._canvas);
	   const me = this;
	   setInterval(() => { me.cycle(); }, 1000) };
    }

    config(div,id,config) {
    }

    isNewMoon() {
        return this._phase == 0
    }

    cycle() {
        this._phase = (this._phase + 1) % 4
		console.log("cycle phase=" + this._phase);
		this.redraw();
    }

    get phase() {
        return this._phase
    }

    get color() {
        return this._color
    }

    set color(value) {
        if (! ["white","silver"].includes(value)) {
            throw Error('invalid value')
        }
        this._color = value
    }

    get size() {
        return this._size
    }
}

export function MoonInstantiate() {
    const divs=document.getElementsByClassName("moon");
    for (let i=0; i<divs.length; ++i) {
        const div=divs[i];
        const id = "moon-" + i;
        const config = JSON.parse(div.getAttribute("data-config"));
        const moon = new Moon(div,id,config)
    }
}
