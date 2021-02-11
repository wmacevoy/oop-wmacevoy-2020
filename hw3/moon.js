class Moon {
    constructor(size, color, phase) {
        this._size = size
        this._color = color
        this._phase = phase
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

module.exports = { 'Moon' : Moon }