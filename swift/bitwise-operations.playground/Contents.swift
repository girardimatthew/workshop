//: Bitwise Operations

let initalNumber: UInt8 = 1
let invertedNumber = ~initalNumber
print(invertedNumber)


let initialBits: UInt8 = 0b11111111
let invertedBits = ~initialBits
print(invertedBits)


let initalNumber_sign: Int = 1
let invertedNumber_sign = ~initalNumber_sign
print(invertedNumber_sign)

print(Int8(bitPattern: 0b11111110))
print(0b11111110)


var xBits = 0b10000011
var yBits = 0b11111111
var result = xBits & yBits
print("Binary:",String(result, radix: 2))
print(result)

xBits = 0b10000011
yBits = 0b11111111
result = xBits | yBits
print("Binary:", String(result, radix: 2))
print(result)

xBits = 0b10000011
yBits = 0b11111111
result = xBits ^ yBits
print("Binary:", String(result, radix: 2))
print(result)

var someBits: UInt8 = 0b11000100
print(someBits << 1)

var someMoreBits: UInt8 = 4
print(someBits >> 1)

var someOtherBits: Int = -4
print(someBits >> 1)


//Exercise 1. Given an integer x, write a function reverseBytes(x) that returns an integer
//whose bytes are reversed. For example, reverseBytes(3628) = 739115008 because 3628 =
//0x00000E2C and 739115008 = 0x2C0E0000

var x : UInt32 = 3628
func reverseBytes(_ n: UInt32) -> UInt32 {
    var n: UInt32 = n
    var m: UInt32 = 0
    var i: UInt32 = 32
    
    while i > 0 && n != 0 {
        m = m << 1 + n & 0b1
        n = n >> 1
        i -= 1
    }
    m = m << i
    return m
}

print(reverseBytes(x))
print(reverseBytes(43261596))
print(reverseBytes(15))


//print(String(x, radix: 2))
//print(String(reverseBytes(x), radix: 2))
//
//print(String(0 << 1, radix: 2))
