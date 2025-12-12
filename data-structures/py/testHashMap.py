#!/usr/bin/python

class HashTable:
	def __init__(self, size):
		self.size = size
		self.hash_table = self.create_lists()

	def create_lists(self):
		return [[] for _ in range(self.size)]

	def getIdx(self, key):
		return hash(key) % self.size

	def add(self, key, val):
		idx = self.getIdx(key)
		self.hash_table[idx].append({key, val})

	def delete(self, *args):
		idx = -1
		if len(args) == 1:
			key = args[0]
			idx = self.getIdx(key)
			if idx in self.hash_table:
				self.hash_table.remove(key)
		elif len(args) == 2:
			key, val = args
			idx = self.getIdx(key)
			if {key, val} in self.hash_table[idx]:
				self.hash_table[idx].remove({key, val})
		else:
			print("invalid number of attributes")
			return


	def get(self, key):
		idx = self.getIdx(key)
		return self.hash_table[idx]

	def __str__(self):
		rc = "";
		for item in self.hash_table:
			if len(item):
				rc += (", ".join(str(it) for it in item)) + ", "
		return rc

if __name__ == "__main__":
	hashInstance = HashTable(20)
	hashInstance.add("1", "1.0")
	hashInstance.add("1", "1.1")
	hashInstance.add("1", "1.3")
	hashInstance.add("2", "2.3")

	print(hashInstance)
	hashInstance.delete("1", "1.1")
	print(hashInstance)


