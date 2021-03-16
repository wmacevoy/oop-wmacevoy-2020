# JS-OOP Example

This is published on github via the url

https://wmacevoy.github.io/oop-wmacevoy/

This automatically publishes anything in the main branch in the docs subfolder
of the github.com/wmacevoy/oop-wmacevoy repo

WARNING: git published /docs NOT js-oo/docs, so I moved this project to /docs!
## Test

```bash
test/*test.js
```
## Clean-Build-Test Screen Capture

![run-test.png](run-test.png)

## Docker

To create a reproducible build (advanced) and you have docker installed, you can do the following:

```bash
docker build -t js-hello .
docker run -i --rm -t js-hello npm test # test
docker run -i --rm -t js-hello node main.js # run
```

## References

1. [Python Unit tests](https://docs.python.org/2/library/unittest.html)


