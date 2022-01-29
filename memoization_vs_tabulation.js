const { performance } = require("perf_hooks");

const memCache = [];
const tabCache = [];

function memFib(n) {
  if (!memcache[n]) {
    if (n < 2) return n;
    return (memcache[n] = memFib(n - 2) + memFib(n - 1));
  }
  return memcache[n];
}

function tabFib(n) {
  tabCache[0] = 0;
  tabCache[1] = 1;
  for (let i = 2; i <= n; i++) {
    tabCache[i] = tabCache[i - 2] + tabCache[i - 1];
  }
  return tabCache[n];
}

let firstStart = performance.now();
memFib(40);
let firstEnd = performance.now();

let secondStart = performance.now();
tabFib(40);
let secondEnd = performance.now();

console.log(
  `Memorization performance is ${
    firstEnd - firstStart
  }  Tabulation performance is ${secondEnd - secondStart}`
);

