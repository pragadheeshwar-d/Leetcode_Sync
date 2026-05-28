var createCounter = function(n) {
    let c = n - 1;
    return function() {
        c += 1;
        return c;
    };
};

/**
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */