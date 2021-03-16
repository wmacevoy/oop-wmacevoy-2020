export class Moon {
    constructor(div, id, config) {
	   this._div = div;
	   this._id = id;
	   this._size = config.size;
	   this._color = config.color;
	   this._phase = config.phase;
       this._div.innerHTML = "Moon(id=" + id + ", color="  + color + ")";
    }

    config(div,id,config) {
    }

    isNewMoon() {
        return this._phase == 0
    }

    cycle() {
        this._phase = (this._phase + 1) % 4
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
